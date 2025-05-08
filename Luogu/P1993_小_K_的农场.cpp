#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int> > > adj(n+10);
	for(int i=1;i<=m;i++){
		int op,a,b,c;
		cin>>op>>a>>b;
		if(op==1){//a-b>=c  -> b<=a-c
			cin>>c;
			adj[a].emplace_back(b,-c);
		} else if(op==2){//a-b<=c -> a<=b+c
			cin>>c;
			adj[b].emplace_back(a,c);
		} else{
			adj[a].emplace_back(b,0);
			adj[b].emplace_back(a,0);
		}
	} 
	for(int i=1;i<=n;i++){
		adj[0].emplace_back(i,0);
	}
	vector<int> d(n+10,1e9),vis(n+10),cnt(n+10);
	queue<int> q;
	d[0]=0;
	vis[0]=1;
	cnt[0]++;
	q.push(0);
	while(q.size()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto [y,w]:adj[x]){
			if(d[y]>d[x]+w){
				d[y]=d[x]+w;
				if(!vis[y]){
					vis[y]=1;
					q.push(y);
					cnt[y]++;
					if(cnt[y]==n+1){
						cout<<"No\n";
						return;
					}
				}
			}
		}
	}
	cout<<"Yes\n";
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
