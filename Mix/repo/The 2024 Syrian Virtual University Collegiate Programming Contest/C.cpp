#include <bits/stdc++.h>

using namespace std;

const long long INF=1e18;

void solve(){
	long long n,k;
	cin>>n>>k;
	vector<long long> a(n+1),pre(n+1);
	vector<vector<long long> > dp(n+10,vector<long long>(n+10,INF) );
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		for(int j=1;j<=i;j++){
			long long res=INF;
			for(int k=j;k<=i;k++){
				long long ress=0;
				ress=a[k]*(k-j)-(pre[k-1]-pre[j-1]);
				ress+=(pre[i]-pre[k])-(a[k]*(i-k));
				res=min(res,ress);
			}
			for(int k=1;k<=n;k++){
				dp[i][k]=min(dp[i][k],dp[j-1][k-1]+res);
			}
		}
	}
	// for(int i=1;i<=n;i++){
		// for(int j=0;j<=n;j++){
			// cout<<dp[i][j]<<" \n"[j==n];
		// }
	// }
	for(int i=1;i<=n;i++){
		// cout<<dp[n][i]<<" \n"[i==n];
		if(dp[n][i]<=k){
			cout<<i<<'\n';
			return;
		}
	}
}

//1 2 3 4 5
//    j k i  

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