#include <bits/stdc++.h>

using namespace std;

constexpr int N=2e5+10;
constexpr int M=2e5;

struct SegmentTree{
	vector<int> ls,rs,val;
	int n;
	int tot;
	void clear(int n){
		this->n=n;
		tot=0;
		ls.assign(N*20,{});
		rs.assign(N*20,{});
		val.assign(N*20,{});
	}
	void insert(int &rt,int pre,int l,int r,int v,int k){
		rt=++tot;
		if(l==r){
			val[rt]=k;
			return;
		}
		int mid=(l+r)>>1;
		if(v<=mid) insert(ls[rt],ls[pre],l,mid,v,k),rs[rt]=rs[pre];
		if(mid<v) insert(rs[rt],rs[pre],mid+1,r,v,k),ls[rt]=ls[pre];
		val[rt]=min(val[ls[rt]],val[rs[rt]]);
	}
	void insert(int &rt,int pre,int v,int k){
		insert(rt,pre,0,M,v,k);
	}
	int find(int rt,int l,int r,int x){
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(val[ls[rt]]>=x) return find(rs[rt],mid+1,r,x);
		else return find(ls[rt],l,mid,x);
	}
	int find(int rt,int x){
		return find(rt,0,M,x);
	}
}seg;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+10);
	vector<int> root(n+10);
	seg.clear(M);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		seg.insert(root[i],root[i-1],a[i],i);
	}
	while(m--){
		int l,r;
		cin>>l>>r;
		cout<<seg.find(root[r],l)<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}