#include <bits/stdc++.h>

using namespace std;

struct HLD{
	int n;
	int root=1;
	vector<long long> num,lz;
	vector<int> dep,siz,son,top,dfn,rnk,f;
	vector<vector<int> > adj;
	int tot;
	HLD(int n){
		init(n);
	}
	void init(int n){
		this->n=n;
		tot=0;
		num.assign(n<<2,{});
		lz=num;
		dep.assign(n+10,{});
		son.assign(n+10,-1);
		f=siz=top=dfn=rnk=dep;
		adj.assign(n+10,{});
	}
	void add_edge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs1(int x,int fa){
		f[x]=fa;
		dep[x]=dep[fa]+1;
		siz[x]=1;
		for(auto y:adj[x]){
			if(y==fa) continue;
			dfs1(y,x);
			if(son[x]==-1||siz[y]>siz[son[x]]){
				son[x]=y;
			}
			siz[x]+=siz[y];
		}
	}
	void dfs2(int x,int tp){
		top[x]=tp;
		dfn[x]=++tot;
		rnk[tot]=x;
		if(son[x]!=-1) dfs2(son[x],tp);
		for(auto y:adj[x]){
			if(y==f[x]||y==son[x]) continue;
			dfs2(y,y);
		}
	}
	void pushup(int rt){
		num[rt]=(num[rt<<1]+num[rt<<1|1]);
	}
	void pushdown(int rt,int l,int r){
		if(lz[rt]){
			int mid=(l+r)>>1;
			num[rt<<1]+=lz[rt]*(mid-l+1);
			num[rt<<1|1]+=lz[rt]*(r-mid);
			lz[rt<<1]+=lz[rt];
			lz[rt<<1|1]+=lz[rt];
			lz[rt]=0;
		}
	}
	void update(int rt,int x,int y,int l,int r,int k){
		if(x<=l&&r<=y){
			num[rt]+=1ll*(r-l+1)*k;
			lz[rt]+=k;
			return;
		}
		pushdown(rt,l,r);
		int mid=(l+r)>>1;
		if(x<=mid) update(rt<<1,x,y,l,mid,k);
		if(mid<y) update(rt<<1|1,x,y,mid+1,r,k);
		pushup(rt);
	}
	void update(int x,int y,int k){
		update(1,x,y,1,n,k);
	}
	long long query(int rt,int x,int y,int l,int r){
		if(x<=l&&r<=y){
			return num[rt];
		}
		pushdown(rt,l,r);
		int mid=(l+r)>>1;
		long long res=0;
		if(x<=mid) res+=query(rt<<1,x,y,l,mid);
		if(mid<y) res+=query(rt<<1|1,x,y,mid+1,r);
		return res;
	}
	long long query(int x,int y){
		return query(1,x,y,1,n);
	}
	long long to_root(int x){
		long long res=0;
		while(x!=root){
			if(top[x]==root){
				res+=query(dfn[root]+1,dfn[x]);
				x=root;
			}
			else{
				res+=query(dfn[top[x]],dfn[x]);
				x=f[top[x]];
			}
		}
		res+=query(dfn[root],dfn[root]);
		return res;
	}
};

void solve() {
	int n,m;
	cin>>n>>m;
	HLD tr(n);
    vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
        int u,v;
		cin>>u>>v;
		tr.add_edge(u,v);
	}
    tr.dfs1(1,1);
    tr.dfs2(1,1);
    for(int i=1;i<=n;i++){
        tr.update(tr.dfn[i],tr.dfn[i],a[i]);
    }
	for(int i=1;i<=m;i++){
		int op,x,a;
		cin>>op>>x;
		if(op==1){
			cin>>a;
			tr.update(tr.dfn[x],tr.dfn[x],a);
		}
		else if(op==2){
			cin>>a;
			tr.update(tr.dfn[x],tr.dfn[x]+tr.siz[x]-1,a);
		}
		else{
			cout<<tr.to_root(x)<<'\n';
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}