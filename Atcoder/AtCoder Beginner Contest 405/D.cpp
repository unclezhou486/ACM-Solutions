#include<bits/stdc++.h>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

char ch[4]={'<','>','^','v'};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<char> > a(n+10,vector<char>(m+10)),ans(n+10,vector<char>(m+10));
	queue<pair<int,int> > q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='E'){
				q.push({i,j});
				ans[i][j]='E';
			}
			else if(a[i][j]=='#'){
				ans[i][j]='#';
			}
			else{
				ans[i][j]=' ';
			}
		}
	}
	while(q.size()){
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m||ans[xx][yy]!=' ') continue;
			ans[xx][yy]=ch[i];
			q.push({xx,yy});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j];
		}
		cout<<'\n';
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
