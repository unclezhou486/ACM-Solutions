#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<long double> x(n+10),y(n+10),dp(n+10);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	long double ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i]=max(dp[i],dp[j]+sqrt((x[i]-x[j+1])*(x[i]-x[j+1])+(y[i]-y[j+1])*(y[i]-y[j+1])));
		}
		ans=max(ans,dp[i]);
	}
	cout<<fixed<<setprecision(10)<<ans<<'\n';
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
