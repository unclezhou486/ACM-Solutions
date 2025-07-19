#include <bits/stdc++.h>

using namespace std;

long long lcm(int x,int y){
	return 1ll*x/gcd(x,y)*y;
}

void solve(){
	int n,x;
	cin>>n>>x;
	vector<vector<int> > adj(n+10);
	vector<int> a(n+10);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	long long ansres=0;
	auto dfs = [&](auto self,int vx,int fa,int lcmnum) -> void{
		for(auto y:adj[vx]){
			if(y==fa) continue;
			long long resnum=lcm(lcmnum,a[y]);
			if(resnum>x){
				continue;
			}
			if(resnum==x) ansres++;
			self(self,y,vx,resnum);
		}
	};
	for(int i=1;i<=n;i++){
		dfs(dfs,i,i,a[i]);
		if(a[i]==x) ans++;
	}
	cout<<ans+ansres/2<<'\n';
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