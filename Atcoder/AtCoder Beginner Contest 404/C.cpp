#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> deg(n+10);
	vector<int> f(n+10);
	auto find = [&](auto self,int x) ->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		deg[u]++,deg[v]++;
		int uu=find(find,u),vv=find(find,v);
		if(uu!=vv){
			f[uu]=vv;
		}
	}
	if(n==m){
		bool flag=true;
		set<int> se;
		for(int i=1;i<=n;i++){
			se.insert(find(find,i));
			if(deg[i]!=2){
				flag=false;
			}
		}
		if(flag&&se.size()==1){
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
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