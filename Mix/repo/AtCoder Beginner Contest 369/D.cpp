#include <iostream>
#include <algorithm>

using namespace std;

const int N=2e5+10;

long long dp[N][2];//0 ou 1 ji

long long a[N];
int n;

void solve(){
	cin>>n;
	dp[0][1]=-1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]+2*a[i]);
		dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
	}
	cout<<max(dp[n][0],dp[n][1])<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}