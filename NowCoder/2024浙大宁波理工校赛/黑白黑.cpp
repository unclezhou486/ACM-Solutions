#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> >a(n+10,vector<int> (m+10)),vis(n+10,vector<int>(m+10));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	queue<pair<int,int> >q;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!a[i][j]&&!vis[i][j]){
				cnt++;
				q.push({i,j});
				vis[i][j]=1;
				while(q.size()){
					auto [x,y]=q.front();
					q.pop();
					for(int i=0;i<4;i++){
						int xx=x+dx[i],yy=y+dy[i];
						if(xx>0&&xx<=n&&yy>0&&yy<=m&&!a[xx][yy]&&!vis[xx][yy]){
							vis[xx][yy]=1;
							q.push({xx,yy});
						}
					}
				}
			}
		}
	}
	if(cnt==1){
		cout<<"No\n";
	}
	else cout<<"Yes\n";
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