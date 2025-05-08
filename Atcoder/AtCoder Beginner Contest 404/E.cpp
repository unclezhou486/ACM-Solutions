#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> c(n+10);
	vector<int> a(n+10);
	vector<int> suf(n+10);
	vector<int> dp(n+10,1e9);
	for(int i=1;i<n;i++){
		cin>>c[i];
	}
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=1;i--){
		suf[i]=suf[i+1]+a[i];
	}
	dp[n-1]=0;
	for(int i=n-1;i>0;i--){
		// cout<<suf[i]<<' ';
		if(!suf[i+1]) dp[i]=0;
		for(int j=i-1;j>=max(i-c[i],0);j--){
			dp[j]=min(dp[j],dp[i]+1);
			if(a[j]) break;
		}
	}
	cout<<dp[0]<<'\n';
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