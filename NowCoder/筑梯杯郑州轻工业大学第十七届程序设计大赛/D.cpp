#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<char> > c(n+10,vector<char>(m+10) );
	vector<vector<int> > vis(n+10,vector<int>(m+10) );
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	auto check = [&](int xx,int yy) -> bool {
		if(xx<1||xx>n||yy<1||yy>m||c[xx][yy]=='#') return false;
		else return true;
	};
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[i][j]&&c[i][j]=='.'){
				queue<pair<int,int> > q;
				q.push({i,j});
				vis[i][j]=++cnt;
				while(q.size()){
					auto [x,y]=q.front();
					q.pop();
					for(int i=0;i<4;i++){
						int xx=x+dx[i],yy=y+dy[i];
						if(!check(xx,yy)||vis[xx][yy]) continue;
						vis[xx][yy]=cnt;
						q.push({xx,yy});
					}
				}
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int xm,ym,xz,yz,xe,ye;
		cin>>xm>>ym>>xz>>yz>>xe>>ye;
		if(vis[xm][ym]==vis[xz][yz]&&vis[xz][yz]==vis[xe][ye]){
			if((xm+ym)%2==(xz+yz)%2){
				// cout<<"Yes\n";
				int dis1=abs(xe-xm)+abs(ye-ym);
				int dis2=abs(xe-xz)+abs(ye-yz);
				if(dis1==1&&dis2==1){
					cout<<"Yes\n";
				}
				else if(dis1==1){
					int x=xm,y=ym;
					int cnt=0;
					for(int i=0;i<4;i++){
						int xx=x+dx[i],yy=y+dy[i];
						if(check(xx,yy)) cnt++;
					}
					if(cnt!=1){
						cout<<"Yes\n";
					}
					else{
						cout<<"No\n";
					}
				}
				else if(dis2==1){
					int x=xz,y=yz;
					int cnt=0;
					for(int i=0;i<4;i++){
						int xx=x+dx[i],yy=y+dy[i];
						if(check(xx,yy)) cnt++;
					}
					if(cnt!=1){
						cout<<"Yes\n";
					}
					else{
						cout<<"No\n";
					}					
				}
				else{
					cout<<"Yes\n";
				}
			}
			else {
				cout<<"No\n";
			}
		}
		else{
			cout<<"No\n";
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