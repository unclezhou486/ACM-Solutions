#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n;
int col[N];

int root[N];
long long ans=0;
struct node{
	int l,r,num;
}tr[N<<5];
int tot;

void update(int x,int &rt,int l=1,int r=n){
	if(!rt) rt=++tot;
	if(l==r){
		tr[rt].num=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(x,tr[rt].l,l,mid);
	if(mid<x) update(x,tr[rt].r,mid+1,r);
	tr[rt].num=tr[tr[rt].l].num+tr[tr[rt].r].num;
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	tr[x].l=merge(tr[x].l,tr[y].l);
	tr[x].r=merge(tr[x].r,tr[y].r);
	if(!tr[x].l&&!tr[y].l&&!tr[x].r&&!tr[y].r){
		ans+=1ll*tr[x].num*tr[y].num;
	}
	tr[x].num+=tr[y].num;
	return x;
}

vector<int> adj[N];

void init(){
	for(int i=1;i<=n;i++) adj[i].clear();
	for(int i=1;i<=tot;i++){
		tr[i].l=tr[i].r=tr[i].num=0;
	}
	tot=0;
	for(int i=1;i<=n;i++) root[i]=0;
	ans=0;
}

void dfs(int x,int fa){
	update(col[x],root[x]);
	for(auto y:adj[x]){
		if(y==fa) continue;
		dfs(y,x);
		root[x]=merge(root[x],root[y]);
		update(col[x],root[x]);
	}
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>col[i];
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,1);
	cout<<ans<<'\n';
	init();
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