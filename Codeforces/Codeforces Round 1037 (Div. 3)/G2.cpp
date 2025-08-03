#include <bits/stdc++.h>

using namespace std;


struct node{
	int premax=-1e9,sufmax=-1e9,sum=-1e9;
	node operator + (const node &a) const{
		node c;
		if(premax==-1e9){
			c=a;
		}
		else if(a.premax==-1e9){
			c=*this;
		}
		else{
			c.premax=max(sum+a.premax,premax);
			c.sufmax=max(sufmax+a.sum,a.sufmax);
			c.sum=sum+a.sum;
		}
		return c;
	}
};

struct segmentTree{
	int n;
	vector<node> num;
	segmentTree(int n){
		init(n);
	}
	void init(int n){
		this->n=n;
		num.assign((n+1)<<2,{});
	}
	void modify(int rt,int x,int l,int r,int k){
		if(l==r){
			num[rt]={max(k,0),max(k,0),k};
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid) modify(rt<<1,x,l,mid,k);
		else modify(rt<<1|1,x,mid+1,r,k);
		num[rt]=num[rt<<1]+num[rt<<1|1];
	}
	void modify(int x,int k){
		modify(1,x,1,n,k);
	}
	node query(int rt,int x,int y,int l,int r){
		if(x>y) return node{0,0,0};
		if(x<=l&&r<=y){
			return num[rt];
		}
		int mid=(l+r)>>1;
		node res;
		if(x<=mid) res=query(rt<<1,x,y,l,mid)+res;
		if(mid<y) res=res+query(rt<<1|1,x,y,mid+1,r);
		return res;
	}
	node query(int x,int y){
		return query(1,x,y,1,n);
	}
};

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1),L(n+1),R(n+1);
	vector<vector<int>>  id(n+1);
	stack<pair<int,int> > st;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		id[a[i]].push_back(i);
	}
	st.push({0,0});
	for(int i=1;i<=n;i++){
		while(st.size()&&st.top().first>=a[i]) st.pop();
		L[i]=st.top().second+1;
		st.push({a[i],i});
	}
	while(!st.empty()) st.pop();
	st.push({0,n+1});
	for(int i=n;i>=1;i--){
		while(st.size()&&st.top().first>a[i]) st.pop();
		R[i]=st.top().second-1;
		st.push({a[i],i});
	}
	segmentTree seg(n);
	for(int i=1;i<=n;i++){
		seg.modify(i,1);
	}
	int ans=0;
	for(int minnum=1,medium=1;minnum<=n;minnum++){
		for(auto x:id[minnum]){
			while(medium<=n&&seg.query(L[x],x-1).sufmax+(minnum>=medium ? 1 : -1)+seg.query(x+1,R[x]).premax>=0){
				for(auto y:id[medium]){
					seg.modify(y,-1);
				}
				medium++;
			}
		}
		ans=max(medium-1-minnum,ans);
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

/*

1 2 3 4 5

*/