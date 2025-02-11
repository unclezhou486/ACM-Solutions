#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> > son(n+10);
	vector<int> ans(n+10,2e9);
	vector<int> vis(n+10),dep(n+10);
	vector<vector<int> > de(n+10);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			dep[x]=dep[i]+1;
			son[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		de[dep[i]].push_back(i);
	}
	set<pair<int,int> > se;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		se.insert({u,v});
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		vis[x]=1;
		ans[x]=0;
	}
	for(int i=n;i>=0;i--){
		if(de[i].size()==0) continue;
		for(auto x:de[i]){
			for(auto y:son[x]){
				if(vis[y]) vis[x]+=1;
			}
		}
	}
	for(int i=n;i>=0;i--){
		if(de[i].size()==0) continue;
		for(auto x:de[i]){
			if(son[x].size()==0) continue;
			// set<int> see;
			if(son[x].size()==vis[x]){
				int res=0;
				for(auto y:son[x]){
					// see.insert(ans[y]);
					res+=ans[y];
				}
				// if(see.size()==1){
					ans[x]=min(res,ans[x]);	
				// }
				// else{
					// for(auto y:son[x]){
					// 	if(se.find({x,y})!=se.end()){
					// 		ans[x]=min(ans[x],ans[y]+1);
					// 	}
					// }
				// }
			}
			// else{
				for(auto y:son[x]){
					if(se.find({x,y})!=se.end()){
						ans[x]=min(ans[x],ans[y]+1);
					}
				}
			// }
		}
	}
	if(ans[1]==2e9) ans[1]=-1;
	cout<<ans[1]<<'\n';
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