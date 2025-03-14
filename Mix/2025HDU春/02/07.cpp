#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

int dp[101][101][3][20][20];

int dx[2]={0,-1};
int dy[2]={-1,0};

//+ - *

void solve(){
	memset(dp,0,sizeof dp);
	int n,m,k;
 	cin>>n>>m>>k;
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
	dp[1][1][0][0][a[1][1]-'0']=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			for(int ii=0;ii<2;ii++){
				int x=i+dx[ii],y=j+dy[ii];
				for(int q=0;q<k;q++){
					for(int w=0;w<k;w++){
						// for(int e=0;e<k;e++){
							if(!(!check(i,j)&&!check(x,y))){
								// dp[i][j][0][q][w][e];
								if(check(i,j)){
									// for(int op=0;op<2;op++){
									(dp[i][j][0][q][((w*10)+(a[i][j]-'0'))%k]+=dp[x][y][0][q][w])%=mod;
									(dp[i][j][1][q][((w*10)+(a[i][j]-'0'))%k]+=dp[x][y][1][q][w])%=mod;
									// for(int e=0;e<k;e++){
										(dp[i][j][2][q][(w*(10+(a[i][j]-'0')))%k]+=dp[x][y][2][q][w])%=mod;
									// }
									// }
								}
								else{
									if(a[i][j]=='+'){
										(dp[i][j][0][(q+w)%k][0]+=dp[x][y][0][q][w])%=mod;
										(dp[i][j][0][(q-w+k)%k][0]+=dp[x][y][1][q][w])%=mod;
										// for(int e=0;e<k;e++){
											(dp[i][j][0][(q+w)%k][0]+=dp[x][y][2][q][w])%=mod;
										// }
									}
									else if(a[i][j]=='-'){
										(dp[i][j][1][(q+w)%k][0]+=dp[x][y][0][q][w])%=mod;
										(dp[i][j][1][(q-w+k)%k][0]+=dp[x][y][1][q][w])%=mod;
										// for(int e=0;e<k;e++){
											(dp[i][j][1][(q+w)%k][0]+=dp[x][y][2][q][w])%=mod;								
										// }
									}
									else{
										(dp[i][j][2][q][w]+=dp[x][y][0][q][w])%=mod;
										(dp[i][j][2][q][(k-w)%k]+=dp[x][y][1][q][w])%=mod;
										// for(int e=0;e<k;e++){
											(dp[i][j][2][q][w]+=dp[x][y][2][q][w])%=mod;
										// }
									}
								}
							}
						// }
					}
				}

			}
		}
	}
	long long ans=0;
	for(int q=0;q<k;q++){
		for(int w=0;w<k;w++){
			if((q+w)%k==0)ans+=dp[n][m][0][q][w];
			if((q==w))ans+=dp[n][m][1][q][w];
			ans%=mod;
			// for(int e=0;e<k;e++){
				if((q+w)%k==0){
					ans+=dp[n][m][2][q][w];
					ans%=mod;
				}
			// }
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