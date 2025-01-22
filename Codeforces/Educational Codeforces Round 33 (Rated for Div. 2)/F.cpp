#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e5+10;
constexpr int M=1e6+10;
int n,r;
int a[N];
int m;
int dfn[N],siz[N],dep[N];
int cnt;
int root[N];

vector<int> de[N];
vector<int> adj[N];

struct SegmentTree{
	vector<int> ls;
	vector<int> rs;
	vector<int> sum;
	int tot,n;
	void clear(int x){
		tot=0;
		n=x;
		ls.assign(M*18,{});
		rs.assign(M*18,{});
		sum.assign(M*18,2e9);
	}
	void insert(int &tr,int pre,int l,int r,int v,int k){
		tr=++tot;
		sum[tr]=min(sum[pre],k);
		if(l==r) return;
		int mid=(l+r)>>1;
		if(v<=mid) insert(ls[tr],ls[pre],l,mid,v,k),rs[tr]=rs[pre];
		else insert(rs[tr],rs[pre],mid+1,r,v,k),ls[tr]=ls[pre];
	}
	void insert(int &tr,int pre,int v,int k){
		insert(tr,pre,1,n,v,k);
	}
	int query(int tr,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr) return sum[tr];
		int mid=(l+r)>>1;
		int ans=2e9;
		if(ql<=mid) ans=min(ans,query(ls[tr],l,mid,ql,qr));
		if(mid<qr) ans=min(ans,query(rs[tr],mid+1,r,ql,qr));
		return ans;
	}
	int query(int tr,int ql,int qr){
		return query(tr,1,n,ql,qr);
	}
}seg;

void dfs(int x,int fa){
	dfn[x]=++cnt;
	siz[x]=1;
	dep[x]=dep[fa]+1;
	de[dep[x]].push_back(x);
	for(auto y:adj[x]){
		if(y==fa) continue;
		dfs(y,x);
		siz[x]+=siz[y];
	}
}

void solve(){
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	seg.clear(n);
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(r,0);
	for(int i=1;i<=n;i++){
		seg.insert(root[i],root[i-1],1,2e9);
		for(auto x:de[i]){
			seg.insert(root[i],root[i],dfn[x],a[x]);
		}
	}
	cin>>m;
	int la=0;
	for(int i=1;i<=m;i++){
		int x,k;
		cin>>x>>k;
		x=(x+la)%n+1,k=(k+la)%n;
		int ans=seg.query(root[min(n,dep[x]+k)],dfn[x],dfn[x]+siz[x]-1);
		cout<<ans<<'\n';
		la=ans;
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