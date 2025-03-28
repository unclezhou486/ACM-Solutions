#pragma GCC O(2)

#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

int dp[2][101][3][20][20][20];

int dx[2]={0,-1};
int dy[2]={-1,0};

//+ - *

void solve(){
	// memset(dp,0,sizeof dp);
	// memset(vis,0,sizeof vis);
	int n,m,k;
 	cin>>n>>m>>k;
 	for(int i=0;i<=1;i++){
 		for(int j=1;j<=m;j++){
 			for(int op=0;op<3;op++){
 				for(int q=0;q<k;q++){
 					for(int w=0;w<k;w++){
 						for(int e=0;e<k;e++){
 							dp[i][j][op][q][w][e]=0;
 						}
 					}
 				}
 			}
 		}
 	}
	vector<vector<char> > a(n+10,vector<char>(m+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	auto check = [&](int x,int y) -> bool{
		if(a[x][y]<'0'||a[x][y]>'9') return 0;
		else return 1;
	};
	dp[1][1][0][0][(a[1][1]-'0')%k][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			for(int ii=0;ii<2;ii++){
				int x=i+dx[ii],y=j+dy[ii];
				int u=(i%2),v=(x%2);
				if(!(!check(i,j)&&!check(x,y))){
					for(int q=0;q<k;q++){
						for(int w=0;w<k;w++){
							// for(int e=0;e<k;e++){
								// if(!(!check(i,j)&&!check(x,y))){
									// dp[i][j][0][q][w][e];
									if(check(i,j)){
										// for(int op=0;op<2;op++){
										(dp[u][j][0][q][((w*10)+(a[i][j]-'0'))%k][0]+=dp[v][y][0][q][w][0])%=mod;
										(dp[u][j][1][q][((w*10)+(a[i][j]-'0'))%k][0]+=dp[v][y][1][q][w][0])%=mod;
										for(int e=0;e<k;e++){
											(dp[u][j][2][q][((w*10)+(a[i][j]-'0'))%k][e]+=dp[v][y][2][q][w][e])%=mod;
										}
										// }
									}
									else{
										if(a[i][j]=='+'){
											(dp[u][j][0][(q+w)%k][0][0]+=dp[v][y][0][q][w][0])%=mod;
											(dp[u][j][0][(q-w+k)%k][0][0]+=dp[v][y][1][q][w][0])%=mod;
											for(int e=0;e<k;e++){
												(dp[u][j][0][(q+w*e)%k][0][0]+=dp[v][y][2][q][w][e])%=mod;
											}
										}
										else if(a[i][j]=='-'){
											(dp[u][j][1][(q+w)%k][0][0]+=dp[v][y][0][q][w][0])%=mod;
											(dp[u][j][1][(q-w+k)%k][0][0]+=dp[v][y][1][q][w][0])%=mod;
											for(int e=0;e<k;e++){
												(dp[u][j][1][(q+w*e)%k][0][0]+=dp[v][y][2][q][w][e])%=mod;								
											}
										}
										else{
											(dp[u][j][2][q][0][w]+=dp[v][y][0][q][w][0])%=mod;
											(dp[u][j][2][q][0][(k-w)%k]+=dp[v][y][1][q][w][0])%=mod;
											for(int e=0;e<k;e++){
												(dp[u][j][2][q][0][(w*e)%k]+=dp[v][y][2][q][w][e])%=mod;
											}
										}
									}
								// }
							// }
						}
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int op=0;op<3;op++){
				for(int q=0;q<k;q++){
					for(int w=0;w<k;w++){
						for(int e=0;e<k;e++){
							dp[(i+1)%2][j][op][q][w][e]=0;
						}
					}
				}
			}
		}
	}
	long long ans=0;
	int u=n%2;
	for(int q=0;q<k;q++){
		for(int w=0;w<k;w++){
			if((q+w)%k==0)ans+=dp[u][m][0][q][w][0];
			if((q==w))ans+=dp[u][m][1][q][w][0];
			ans%=mod;
			for(int e=0;e<k;e++){
				if((q+(w*e))%k==0){
					ans+=dp[u][m][2][q][w][e];
					ans%=mod;
				}
			}
		}
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