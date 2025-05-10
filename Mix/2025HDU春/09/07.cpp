#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	vector<int> dp(n+10);
	vector<int> vis(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=1;
		dp[a[i]]=1;
		if(vis[a[i]-1]){
			dp[a[i]]=dp[a[i]-1]+1;
		}
	}
	int ans=n;
	for(int i=1;i<=n;i++){
		// cout<<dp[i]<<" \n"[i==]
		ans=min(ans,n-dp[i]);
	}
	int res=1;
	for(int i=1;i<=n;i++){
		if(a[i]==res) res++;
	}
	res--;
	ans=min(n-res,ans);
	res=n;
	for(int i=n;i>=1;i--){
		if(a[i]==res) res--;
	}
	ans=min(res,ans);
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