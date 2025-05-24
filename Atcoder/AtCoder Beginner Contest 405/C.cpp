#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	vector<long long> dp(2);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1]+=dp[0]*a[i];
		dp[0]+=a[i];
	}
	cout<<dp[1]<<'\n';
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
