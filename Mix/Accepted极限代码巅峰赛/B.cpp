#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<long long> a(n+10),pre(n+10);
	vector<long long > dp(n+10);
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=a[i]+pre[i-1];
	long long maxn=-1e18;
	for(int i=k;i<=n;i++){
		maxn=max(maxn,dp[i-k]-pre[i-1]);
		dp[i]=maxn+pre[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	if(k==1) ans=pre[n];
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