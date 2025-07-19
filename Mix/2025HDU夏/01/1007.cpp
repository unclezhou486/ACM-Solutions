#include <bits/stdc++.h>

using namespace std;

long long lcm(int x,int y){
	return 1ll*x/gcd(x,y)*y;
}

void solve(){
	int n,valx;
	cin>>n>>valx;
	vector<int> a(n+10);
	vector<vector<int>> adj(n+10);
	vector<map<int,int> > cnt(n+10);
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
	auto dfs = [&](auto self,int x,int fa) -> void{
		if(valx%a[x]==0){
			cnt[x][a[x]]=1;
		}
		if(a[x]==valx) ans++;
		for(auto y:adj[x]){
			if(y==fa) continue;
			self(self,y,x);
			for(auto [d1,cnt1]:cnt[x]){
				for(auto [d2,cnt2]:cnt[y]){
					if(lcm(d1,d2)==valx){
						ans+=1ll*cnt1*cnt2;
					}
				}
			}
			for(auto [d2,cnt2]:cnt[y]){
				// +=cnt2;
				long long lcmnum=lcm(d2,a[x]);
				if(valx%lcmnum==0){
					cnt[x][lcmnum]+=cnt2;
				}
			}
		}
	};
	dfs(dfs,1,1);
	cout<<ans<<'\n';
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