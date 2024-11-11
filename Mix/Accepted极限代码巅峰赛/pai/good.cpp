#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<long long> a(n+10),pre(n+10);
	// vector<long long > dp(n+10);
	vector<vector<long long> >  dp(n+10,vector<long long> (n+10,-INF) );
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=a[i]+pre[i-1];
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			for(int q=1;q<=k;q++){
				dp[i][q%k]=max(dp[i][q%k],dp[j][q-1]+(q==k?pre[i]-pre[j]:0));
			}
		}
	}
	long long ans=0;
	for(int i=k;i<=n;i++){
		ans=max(ans,dp[i][0]);
	}
	if(k==1) ans=pre[n];
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}