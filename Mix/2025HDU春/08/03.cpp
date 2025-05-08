#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > a(n+10,vector<int>(m+10)) ;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		while(x--){
			int y;
			cin>>y;
			a[i][y]=1;
		}
	}
	int ans=1e9;
	// for(int i=1;i<=n;i++){
		vector<vector<int> > d(n+10,vector<int>(m+10,1e9) );
		queue<pair<int,int> > q;
		for(int i=1;i<=n;i++){
			if(!a[i][1]){
				d[i][1]=1;
				q.push({i,1});
			}
		}
		// d[i][1]=1;
		// q.push({i,1});
		while(q.size()){
			auto [x,y]=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int xx=x+dx[i],yy=y+dy[i];
				if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]) continue;
				if(d[xx][yy]>d[x][y]+1){
					d[xx][yy]=d[x][y]+1;
					q.push({xx,yy});
				} 
			}
		}
		for(int j=1;j<=n;j++){
			ans=min(ans,d[j][m]);
		}
	// }
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