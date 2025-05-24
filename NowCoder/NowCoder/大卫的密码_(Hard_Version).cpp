#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	vector<vector<int> > a(n+10,vector<int>(m+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	vector<vector<int> > dp(n+10,vector<int>(m+10,-1e9));
	vector<int> pre(n+10),dppre(n+10),dpsuf(n+10);
	// dp[1][1]=a[1][1];
	dp[s][1]=a[s][1];
	for(int j=1;j<=m;j++){
		pre[0]=0;
		for(int i=1;i<=n;i++){
			pre[i]=a[i][j]+pre[i-1];
		}
		// for(int i=1;i<=n;i++){
		// 	cout<<pre[i]<<" \n"[i==n];
		// }
		dppre[0]=-1e9;
		for(int i=1;i<=n;i++){
			dppre[i]=max(dppre[i-1],dp[i][j]-pre[i]);
		}
		dpsuf[n+1]=-1e9;
		for(int i=n;i>=1;i--){
			dpsuf[i]=max(dpsuf[i+1],dp[i][j]+pre[n]-pre[i]);
		}
		for(int i=1;i<=n;i++){
			dp[i][j]=max(max(dppre[i-1],dpsuf[i+1])+pre[i],dp[i][j]);
			dp[i][j+1]=dp[i][j]+a[i][j+1];
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		cout<<dp[i][j]<<" \n"[j==m];
	// 	}
	// }
	cout<<dp[t][m]<<'\n';
}
//dp[i][j]=max( dpp[k]+pre[n]-pre[k]+pre[i] /dpp[k]+pre[i]-pre[k])
//
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

/*

25

33

27

27+18-18

27+9

*/