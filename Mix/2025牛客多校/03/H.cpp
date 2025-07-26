#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int> > f(n+10,vector<int>(21));
	vector<int> vis(n+10),dep(n+10);
	vis[1]=1;
	f[1][0]=1;
	for(int i=2;i<=n;i++){
		cin>>f[i][0];
		dep[i]=dep[f[i][0]]+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=k;i++){
		int u,l,r;
		cin>>u>>l>>r;
		auto get = [&](int x) -> int{
			int res=x;
			if(vis[res]) return res;
			for(int i=20;i>=0;i--){
				if(!vis[f[res][i]]){
					res=f[res][i];
				}
			}
			return f[res][0];
		};
		auto get_by_len = [&](int x,int len) -> int{
			int res=x;
			for(int i=0;i<=20;i++){
				if((len>>i)&1){
					res=f[res][i];
				}
			}
			return res;
		};
		int x=get(u);
		if(x==u){
			cout<<l<<'\n';
			return;
		}
		else if(dep[u]-dep[x]<=(r-l+1)){
			cout<<l+(dep[u]-dep[x]-1)<<'\n';
			return;
		}
		else{
			int y=get_by_len(u,dep[u]-dep[x]-(r-l+1));
			for(;y!=x;y=f[y][0]){
				vis[y]=1;
			}
		}
	}
	cout<<-1<<'\n';
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