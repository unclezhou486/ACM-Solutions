#include <bits/stdc++.h>

using namespace std;

void solve(){
	int t,n,m;
	cin>>t>>n>>m;
	vector<int> a(n+10);
	a[0]=0;
	for(int i=1;i<=n-1;i++){
		cin>>a[i];
	}
	vector<vector<vector<int> > >  dp(n+10,vector<vector<int> >(n*t+10,vector<int>(m+10,1e9)));
	dp[0][0][0]=0;
	auto num = [&](int x) -> int{
		return x*x;
	};
	int nt=n*t;
	for(int i=1;i<n;i++){
		for(int j=0;j<=a[i];j++){
			for(int k=0;k<=m;k++){
				dp[i][a[i]][k]=dp[i-1][j][k]+num(a[i]-j);
			}
		}
		for(int j=0;j<=nt;j++){
			for(int q=j;q<=nt;q++){
				for(int k=0;k<=m;k++){
					int mm=k+abs(q-a[i]);	
					if(k+abs(q-a[i])<=m){
						dp[i][q][mm]=min(dp[i][q][mm],dp[i-1][j][k]+num(q-j));
					}
				}
			}
		}
	}
	int ans=1e9;
	for(int j=0;j<=nt;j++){
		for(int k=0;k<=m;k++){
			dp[n][nt][k]=min(dp[n][nt][k],dp[n-1][j][k]+num(nt-j));
			ans=min(ans,dp[n][nt][k]);
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