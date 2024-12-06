#include <bits/stdc++.h>

using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<vector<int>> adj(n+10);
	vector<int> len(n+10),len1(n+10),siz(n+10);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto dfs = [&](auto self,int x,int fa) -> void {
		int maxn=0;
		int maxnn=0;
		int maxn1=0;
		for(auto y:adj[x]){
			if(y==fa) continue;
			self(self,y,x);
			if(len[y]>maxn){
				maxnn=maxn;
				maxn=len[y];
			}
			else if(len[y]>maxnn){
				maxnn=len[y];
			}
			maxn1=max(maxn1,len1[y]);
		}
		len[x]=maxn+1;
		len1[x]=max(len1[x],maxn1+1);
		if(!maxnn) maxnn=1;
		len1[x]=max(maxn+1+maxnn-1,len1[x]);
	};
	dfs(dfs,1,1);
	cout<<max(len[1],len1[1])<<'\n';

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
	return 0;
}