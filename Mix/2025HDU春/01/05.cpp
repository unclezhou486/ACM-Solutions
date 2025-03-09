#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};



void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<long long> > t(n+10,vector<long long>(m+10) ),d(n+10,vector<long long>(m+10)) ;
	vector<vector<vector<long long> > > dis(n+10,vector<vector<long long> > (m+10,vector<long long>(5,1e18) ) ) ;

	auto check = [&](int x,int y) -> bool {
		if(x<1||x>n||y<1||y>m) return 0;
		else return 1;
	};

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>d[i][j];
		}
	}
	priority_queue<pair<long long,pair<pair<int,int>,int> >,vector<pair<long long,pair<pair<int,int>,int> >>,greater<> > q;
	dis[1][0][0]=0;
	q.push({dis[1][0][0],{{1,0},0}});
	while(q.size()){
		auto [distance,pos] = q.top();
		q.pop();
		auto [ver,op]=pos;
		auto [x,y]=ver;
		for(int i=0;i<4;i++){
			long long res=t[x][y];
			if(i!=op){
				res+=d[x][y];
			}
			int xx=x+dx[i],yy=y+dy[i];
			if(!check(xx,yy)) continue;
			if(distance+res<dis[xx][yy][i]){
				dis[xx][yy][i]=distance+res;
				q.push({dis[xx][yy][i],{{xx,yy},i} } );
			}
		}
	}
	long long ans=dis[n][m][3]+t[n][m];
	for(int i=0;i<3;i++){
		ans=min(ans,dis[n][m][i]+d[n][m]+t[n][m]);
	}
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