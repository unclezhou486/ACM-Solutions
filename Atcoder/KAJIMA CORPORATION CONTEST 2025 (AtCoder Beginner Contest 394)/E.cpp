#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<char> > a(n+10,vector<char>(n+10) ) ;
	vector<vector<int> > dis(n+10,vector<int>(n+10,1e9));
	queue<pair<int,int> > q;
	for(int i=1;i<=n;i++) q.push({i,i}),dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(i!=j&&a[i][j]!='-'){
				q.push({i,j});
				dis[i][j]=1;
			}
		}
	}
	while(q.size()){
		auto [x,y]=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][x]==a[y][j]&&a[i][x]!='-'&&dis[i][j]>dis[x][y]+2){
					q.push({i,j});
					dis[i][j]=dis[x][y]+2;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]==1e9) dis[i][j]=-1;
			cout<<dis[i][j]<<" \n"[j==n];
		}
	}
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
