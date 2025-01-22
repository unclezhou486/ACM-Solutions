#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e5+10;


struct SegmentTree{
	vector<int> ls;
	vector<int> rs;
	vector<int> sum;
	vector<int> cnt;
	int tot,n;
	void clear(int x){
		tot=0;
		n=x;
		ls.assign(N*20,{});
		rs.assign(N*20,{});
		sum.assign(N*20,{});
		cnt.assign(N*20,{});
	}
	void insert(int &tr,int pre,int l,int r,int v,int k){
		tr=++tot;
		sum[tr]=sum[pre]+k;
		cnt[tr]=cnt[pre]+1;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(v<=mid) insert(ls[tr],ls[pre],l,mid,v,k),rs[tr]=rs[pre];
		if(mid<v) insert(rs[tr],rs[pre],mid+1,r,v,k),ls[tr]=ls[pre];
	}
	void insert(int &tr,int pre,int v,int k){
		insert(tr,pre,1,n,v,k);
	}
	int query(int tr,int l,int r,int ql,int qr){
		if(ql<=l&&r<=ql) return sum[tr];
		int mid=(l+r)>>1;
		int ans=0;
		if(ql<=mid) ans=ans+query(ls[tr],l,mid,ql,qr);
		if(mid<qr) ans=ans+query(rs[tr],mid+1,r,ql,qr);
		return ans;
	}
	int query(int tr,int ql,int qr){
		return query(tr,1,n,ql,qr);
	}
	int query1(int tr,int l,int r,int ql,int qr){
		if(ql<=l&&r<=ql) return cnt[tr];
		int mid=(l+r)>>1;
		int ans=0;
		if(ql<=mid) ans=ans+query1(ls[tr],l,mid,ql,qr);
		if(mid<qr) ans=ans+query1(rs[tr],mid+1,r,ql,qr);
		return ans;
	}
	int query1(int tr,int ql,int qr){
		return query1(tr,1,n,ql,qr);
	}
}seg;

void solve(){
	int n,q;
	cin>>n>>q;
	seg.clear(n);
	vector<int> root(n+10),dep(n+10);
	vector<vector<int> > f(n+10,vector<int>(20) );
	vector<vector<tuple<int,int,int> > > adj(n+10);
	for(int i=1;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		adj[a].emplace_back(b,c,d);
		adj[b].emplace_back(a,c,d);
	}
	auto lca = [&](int x,int y) -> int {
		if(dep[x]<dep[y]) swap(x,y);
		for(int i=19;~i;i--){
			if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		}
		if(x==y) return x;
		for(int i=19;~i;i--){
			if(f[x][i]!=f[y][i]){
				x=f[x][i],y=f[y][i];
			}
		}
		return f[x][0];
	};
	auto dfs = [&](auto self,int x,int fa) -> void{
		f[x][0]=fa;
		dep[x]=dep[fa]+1;
		for(int i=1;i<20;i++){
			f[x][i]=f[f[x][i-1]][i-1];
		}
		for(auto [y,c,d]:adj[x]){
			if(y==fa) continue;
			seg.insert(root[y],root[x],c,d);
			self(self,y,x);
		}
	};
	dfs(dfs,1,1);
	while(q--){
		int x,y,u,v;
		cin>>x>>y>>u>>v;
		int res=seg.sum[root[u]]+seg.sum[root[v]]-2*seg.sum[root[lca(u,v)]];
		int ress=seg.query(root[u],x,x)+seg.query(root[v],x,x)-2*seg.query(root[lca(u,v)],x,x);
		// int ans=res-ress+
		int resss=seg.query1(root[u],x,x)+seg.query1(root[v],x,x)-2*seg.query1(root[lca(u,v)],x,x);
		int ans=res-ress+resss*y;
		cout<<ans<<'\n';
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