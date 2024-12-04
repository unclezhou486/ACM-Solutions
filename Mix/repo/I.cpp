#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
constexpr int N=5e5+10;

int n,m;
long long k;

long long a[N];

int root[N<<2],idx;
long long b[N<<2];

struct node{
	int l,r;
	long long num;
}tr[N<<5];
int tot;

void update(int &rt,long long x,int val,long long l=-(k-1),long long r=0){
	if(!rt) rt=++tot;
	tr[rt].num+=val;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(x<=mid) update(tr[rt].l,x,val,l,mid);
	if(mid<x) update(tr[rt].r,x,val,mid+1,r);
	return;
}

int kth(int rt,int cnt,long long l=-(k-1),long long r=0){
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(tr[tr[rt].l].num>=cnt) return kth(tr[rt].l,cnt,l,mid);
	else return kth(tr[rt].r,cnt-tr[tr[rt].l].num,mid+1,r);
}

void del(int x){
	tr[x].l=tr[x].r=tr[x].num=0;
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	tr[x].num+=tr[y].num;
	tr[x].l=merge(tr[x].l,tr[y].l);
	tr[x].r=merge(tr[x].r,tr[y].r);
	del(y);
	return x;
}

void split(int x,int &y,int cnt){
	if(!x) return;
	if(!y) y=++tot;
	int res=tr[tr[x].l].num;
	if(cnt>res){
		split(tr[x].r,tr[y].r,cnt-res);
	}
	else{
		swap(tr[x].r,tr[y].r);
	}
	if(cnt<res){
		split(tr[x].l,tr[y].l,cnt);
	}
	tr[y].num=tr[x].num-cnt;
	tr[x].num=cnt;
	return;
}

int cnt[N<<2];

void upd(int x,int val,int tr=1,int l=1,int r=(n+m)<<1){
	cnt[tr]+=val;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) upd(x,val,tr<<1,l,mid);
	if(mid<x) upd(x,val,tr<<1|1,mid+1,r);
	return;
}

pair<int,int> find(int th,int tr=1,int l=1,int r=(n+m)<<1){
	if(l==r) return {l,0};
	int mid=(l+r)>>1;
	if(cnt[tr<<1]<th){
		auto res=find(th-cnt[tr<<1],tr<<1|1,mid+1,r);
		res.second+=cnt[tr<<1];
		return res;
	}
	else{
		auto res=find(th,tr<<1,l,mid);
		return res;
	}
}

void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=-a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i==1||a[i]/k!=a[i-1]/k){
			++idx;
			b[idx]=a[i]/k;
		}
		upd(idx,1);
		update(root[idx],a[i]%k,1);
	}
	// return;
	int id=1;
	for(int _=1;_<=m;_++){
		char op;
		cin>>op;
		if(op=='C'){
			int t;
			cin>>t;
			while(id<idx&&tr[root[id]].num<=t){
				long long res=min(b[id+1]-b[id],t/tr[root[id]].num);
				b[id]+=res;
				t-=res*tr[root[id]].num;
				if(b[id]==b[id+1]){
					upd(id,-tr[root[id]].num);
					upd(id+1,tr[root[id]].num);
					root[id+1]=merge(root[id+1],root[id]);
					id++;
				}
			}
			b[id]+=(t/tr[root[id]].num);
			t%=tr[root[id]].num;
			if(t){
				if(!root[id+1]){
					b[id+1]=b[id]+1;
					idx=id+1;
				}
				int tmp=0;
				split(root[id],tmp,t);
				root[id+1]=merge(root[id+1],root[id]);
				// swap(root[id],tmp);
				root[id]=tmp;
				upd(id,-t);
				upd(id+1,t);
			}
		}
		else{
			int x;
			cin>>x;
			// x=n-x+1;
			auto [res,cnt]=find(x);
			long long ans=kth(root[res],x-cnt);
			ans+=b[res]*k;
			ans=-ans;
			cout<<ans<<'\n';
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
5 8 8
294 928 293 392 719
A 4
C 200
A 5
C 10
A 2
C 120
A 1
A 3
*/

/*
1 1 10
2 1 5
3 6 10
4 1 3
5 4 5
*/

//2 3 -1
//-9 -7 -3
//-2 -7 -3
//-4 -7 -3
//1 -2 -3
