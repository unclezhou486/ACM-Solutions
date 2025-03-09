#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

constexpr int N=1e5+10;


struct segMentTree{
	int n;
	vector<int> num;
	vector<int> num1;
	void clear(int n){
		num.assign(n*4,{});
		num1.assign(n*4,{});
	}
	void update(int l,int r,int k,int x,int x1,int tr){
		if(l==r){
			num[tr]=x;
			num1[tr]=x1;
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid) update(l,mid,k,x,x1,tr<<1);
		if(mid<k) update(mid+1,r,k,x,x1,tr<<1|1);
		num[tr]=max(num[tr<<1],num[tr<<1|1]);
		num1[tr]=max(num1[tr<<1],num1[tr<<1|1]);
	}
	int query(int l,int r,int x,int y,int tr){
		if(l<=x&&y<=r){
			return num[tr];
		}
		int mid=(x+y)>>1;
		int res=0;
		if(l<=mid) res=max(res,query(l,r,x,mid,tr<<1) ) ;
		if(mid<r) res=max(res,query(l,r,mid+1,y,tr<<1|1));
		return res; 
	}
	int query1(int l,int r,int x,int y,int tr){
		if(l<=x&&y<=r){
			return num1[tr];
		}
		int mid=(x+y)>>1;
		int res=0;
		if(l<=mid) res=max(res,query1(l,r,x,mid,tr<<1) ) ;
		if(mid<r) res=max(res,query1(l,r,mid+1,y,tr<<1|1));
		return res; 		
	}
}sg1;

struct node{
	int x,y,id;
	// cin>>x>>y;
	bool operator<(const node &a){
		return y<a.y;
	}
};

int n,q;
int a[N];
int Maxx0[N][20];
int Maxx1[N][20];
int Minx1[N][20];
int Minx0[N][20];

int to[N][20];

void solve(){
	
	cin>>n>>q;
	// vector<int> a(n+10);
	// vector<vector<int> > Maxx0(n+10,vector<int>(20,-2e9));
	// vector<vector<int> > Maxx1(n+10,vector<int>(20,-2e9));
	// vector<vector<int> > Minx0(n+10,vector<int>(20,2e9));
	// vector<vector<int> > Minx1(n+10,vector<int>(20,2e9));
	// vector<vector<int> > to(n+10,vector<int>(20) ) ;
	for(int i=0;i<n+10;i++){
		for(int j=0;j<20;j++){
			Maxx0[i][j]=-2e9;
			Maxx1[i][j]=-2e9;
			Minx0[i][j]=2e9;
			Minx1[i][j]=2e9;
			// to[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		to[i][0]=i+2;
		if(i%2){
			Maxx1[i][0]=a[i];
			Minx1[i][0]=a[i];
		}
		else{
			Maxx0[i][0]=a[i];
			Minx0[i][0]=a[i];
		}
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			to[j][i]=to[to[j][i-1]][i-1];
			Maxx1[j][i]=max(Maxx1[j][i-1],Maxx1[to[j][i-1]][i-1]);
			Maxx0[j][i]=max(Maxx0[j][i-1],Maxx0[to[j][i-1]][i-1]);
			Minx1[j][i]=min(Minx1[j][i-1],Minx1[to[j][i-1]][i-1]);
			Minx0[j][i]=min(Minx0[j][i-1],Minx0[to[j][i-1]][i-1]);
		}
	}
	auto check = [&] (int l,int r) -> bool {
		if(l==r) return 1;
		else if(l+1==r) return a[l]!=a[r];
		int ll,rr;
		if(r%2!=l%2){
			rr=r;
			ll=l+1;
			l=l;
			r=r-1;
		}
		else{
			rr=r;
			ll=l;
			l=l+1;
			r=r-1;
		}
        if(rr%2==0){
            swap(r,rr);
            swap(l,ll);
        }
		int t=floor(log2(r-l+1))-1;
		int tt=floor(log2(rr-ll+1))-1;
		int max1=max(Maxx1[ll][tt],Maxx1[rr-(1<<(tt+1))+2][tt]);
		int min1=min(Minx0[l][t],Minx0[r-(1<<(t+1))+2][t]);
		int max2=max(Maxx0[l][t],Maxx0[r-(1<<(t+1))+2][t]);
		int min2=min(Minx1[ll][tt],Minx1[rr-(1<<(tt+1))+2][tt]);
		if(max1<min1||max2<min2){
			return 1;
		}
		else{
			return 0;
		}
	};
	vector<pair<int,int> > vec;
	// sg.clear(n);
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		vec.push_back({l,i});
		// sg.update(1,n,l,i,1);
	}
	vector<node> que(q+10);
	vector<int> ans(q+10);
	for(int i=1;i<=q;i++){
		que[i].id=i;
		cin>>que[i].x>>que[i].y;
	}
	sort(que.begin()+1,que.begin()+1+q);
	sg1.clear(n);
	// sg2.clear(n);
	int id=0;
	for(int i=1;i<=q;i++){
		while(id<vec.size()&&vec[id].second<=que[i].y){
			sg1.update(1,n,vec[id].first,vec[id].second,vec[id].second-vec[id].first+1,1);
			id+=1;
		}
		ans[que[i].id]=max(sg1.query(1,que[i].x,1,n,1)-que[i].x+1,sg1.query1(que[i].x+1,que[i].y,1,n,1));
	}
	long long anss=0;
	for(int i=1;i<=q;i++){
		anss=anss+1ll*i*ans[i]%mod;
		anss%=mod;
	}
	cout<<anss<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}