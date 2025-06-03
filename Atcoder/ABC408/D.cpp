#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	vector<vector<vector<int> > > dp(n+10,vector<vector<int> > (2,vector<int>(2,1e9)));
	dp[0][0][0]=0;
	// char la='a';
	for(int i=1;i<=n;i++){
		int res=str[i-1]-'0';
		if(res==0){
			dp[i][0][0]=min(dp[i-1][0][0],dp[i-1][1][0]);
			dp[i][0][1]=min(dp[i-1][0][1],dp[i-1][1][1]);
			dp[i][1][1]=min(dp[i-1][0][0],dp[i-1][1][1])+1;
		}
		else{
			dp[i][0][0]=min(dp[i-1][0][0],dp[i-1][1][0])+1;
			dp[i][0][1]=min(dp[i-1][0][1],dp[i-1][1][1])+1;
			dp[i][1][1]=min(dp[i-1][0][0],dp[i-1][1][1]);
		}
	}
	cout<<min({dp[n][0][0],dp[n][0][1],dp[n][1][1]})<<'\n';
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