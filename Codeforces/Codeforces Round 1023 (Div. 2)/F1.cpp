#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n+10);
	vector<vector<long long> > dp(n+10,vector<long long>(n+10,1e18));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[n][i]=a[i]+(n-i);
	}
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=n;j++){
			dp[i][j]=min(dp[i][j],dp[i+1][j]+a[j]+1);
			if(i<j){
				dp[i][i]=min(dp[i][i],dp[i+1][j]+a[i]);
			}
		}
	}
	long long ans=1e18;
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[1][i]);
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
