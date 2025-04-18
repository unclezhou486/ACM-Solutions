#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<pair<int,long long> > > adj(n+10);
	vector<vector<pair<int,long long> > > adjj(n+10);
	for(int i=1;i<n;i++){
		int u,v,p,q;
		cin>>u>>v>>p>>q;
		adj[u].push_back({v,p});
		adj[v].push_back({u,q});
		adjj[u].push_back({v,p+q});
		adjj[v].push_back({u,p+q});
	}
	int s,t;
	cin>>s>>t;
	vector<int> f(n+10),dep(n+10),vis(n+10),valf(n+10),vals(n+10);
	auto dfs = [&] (auto self,int x,int fa) -> void{
		dep[x]=dep[fa]+1;
		f[x]=fa;
		for(auto [y,w]:adj[x]){
			if(y==fa){
				valf[x]=w;
				continue;
			} 
			vals[y]=w;
			self(self,y,x);
		}
	};
	dfs(dfs,1,0);
	int ss=s,tt=t;
	long long ans=0;
	while(ss!=tt){
		vis[ss]=1,vis[tt]=1;
		if(dep[ss]>dep[tt]){
			ans+=valf[ss];
			ss=f[ss];
		}
		else if(dep[ss]<dep[tt]){
			ans+=vals[tt];
			tt=f[tt];
		}
		else{
			ans+=valf[ss];
			ans+=vals[tt];
			ss=f[ss],tt=f[tt];
		}
	}
    vis[ss]=1;
	// cout<<ans<<'\n';
	auto dfss= [&](auto self,int x) -> long long{
		long long res=0;
		for(auto [y,w]:adjj[x]){
			if(vis[y]) continue;
			vis[y]=1;
			res=max(res,res+w+self(self,y));
		}
		return res;
	};
	ss=s,tt=t;
	while(ss!=tt){
		ans+=dfss(dfss,ss);
		ans+=dfss(dfss,tt);
		vis[ss]=1,vis[tt]=1;
		if(dep[ss]>dep[tt]){
			ss=f[ss];
		}
		else if(dep[ss]<dep[tt]){
			tt=f[tt];
		}
		else{
			ss=f[ss],tt=f[tt];
		}
	}
	ans+=dfss(dfss,ss);
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}