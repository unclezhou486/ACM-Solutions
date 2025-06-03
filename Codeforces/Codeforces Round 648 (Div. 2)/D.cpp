#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<char> > a(n+10,vector<char>(m+10));
	vector<vector<int> > vis(n+10,vector<int>(m+10));
	vector<pair<int,int> > be;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='B'){
				be.emplace_back(i,j);
			}
			else if(a[i][j]=='G'){
				cnt++;
				// ge.emplace_back(i,j);
			}
		}
	} 	
	for(auto [x,y]:be){
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
				if(a[xx][yy]=='G'){
					cout<<"No\n";
					return;
				}
				else if(a[xx][yy]=='.'){
					a[xx][yy]='#';
				}
			}
		}
	}
	
	queue<pair<int,int> > q;
	if(a[n][m]=='.')q.push({n,m});
	int anscnt=0;
	while(q.size()){
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
				vis[xx][yy]=1;
				if(a[xx][yy]=='.'){
					q.emplace(xx,yy);
				}
				else if(a[xx][yy]=='G'){
					anscnt++;
					q.emplace(xx,yy);
				}
			}
		}
	}
	if(anscnt==cnt){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
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