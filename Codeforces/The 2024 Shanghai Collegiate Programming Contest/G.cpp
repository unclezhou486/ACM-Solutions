#include <bits/stdc++.h>

using namespace std;

constexpr int mod=998244353;
constexpr int N=1e2+10;

int dp[N][N][(1<<10)];
int mx[20],my[20];

bool vis[N][N];

int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

int dxx[8]={-1,-1,1,1,1,1,-1,-1};
int dyy[8]={1,1,1,1,-1,-1,-1,-1};

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>mx[i]>>my[i];
	}
	set<pair<int,int> > see;
	int statee=(1<<m)-1;
	for(int l=0;l<m;l++){
		if((statee>>l)&1){
			see.insert({mx[l+1],my[l+1]});
		}
	}
	bool flag=true;
	for(int l=0;l<8;l++){
		int xx=dx[l],yy=dy[l];
		int xxx=dxx[l],yyy=dyy[l];
		if(see.find({xx,yy})!=see.end()&&see.find({xxx,yyy})==see.end()){
			flag=false;
		}
	}
	if(flag){
		dp[0][0][statee]=1;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0&&j==0) continue;
			// map<int,int> ma;
			for(int k=0;k<(1<<m);k++){
				// set<pair<int,int> > se;
				for(int l=0;l<m;l++){
					if((k>>l)&1){
						vis[mx[l+1]][my[l+1]]=1;
						// se.insert({mx[l+1],my[l+1]});
					}
					else{
						vis[mx[l+1]][my[l+1]]=0;
					}
				}
				bool flag=true;
				for(int l=0;l<8;l++){
					int xx=i+dx[l],yy=j+dy[l];
					int xxx=i+dxx[l],yyy=j+dyy[l];
					// if(se.find({xx,yy})!=se.end()&&se.find({xxx,yyy})==se.end()){
					if(xx<0||xx>n||yy<0||yy>n) continue;
					if(vis[xx][yy]&&!vis[xxx][yyy]){	
						flag=false;
					}
				}
				// for(int l=0;l<m;l++){
				// 	if((k>>l)&1){
				// 		int ddx=mx[l+1]-i;
				// 		int ddy=my[l+1]-i;
				// 		if((abs(ddx)==2&&abs(ddy)==1)||(abs(ddy)==2&&abs(ddx)==1)){
				// 			if(abs(ddx)==2){
				// 				ddx/=2;
				// 				int xxx=i+ddx,yyy=i+ddy;
				// 			}
				// 			else{
				// 				ddy/=2;
				// 			}
				// 		}
				// 	}
				// }
				if(flag){
					int state=k;
					for(int l=0;l<m;l++){
						if(((k>>l)&1)&&mx[l+1]==i&&my[l+1]==j){
							state-=(1<<l);
						}
					}
					if(i-1>=0) dp[i][j][state]=(dp[i][j][state]+dp[i-1][j][k])%mod;
					if(j-1>=0) dp[i][j][state]=(dp[i][j][state]+dp[i][j-1][k])%mod;
					// if(i==0&&j==0&&k) dp[i][j][state]=1;
				}
			}
		}
	}
	int ans=0;
	for(int k=0;k<(1<<m);k++){
		ans=(ans+dp[n][n][k])%mod;
	}
	cout<<ans<<'\n';
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