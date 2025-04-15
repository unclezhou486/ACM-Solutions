#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

long long qmi(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

void solve(){
	int n,k;
	cin>>n>>k;
	// vector<vector<int> > dp(n+10,vector<int>(k+10) ) ;
	// dp[0][0]=1;
	// for(int i=1;i<=n;i++){
	// 	int res=0;
	// 	for(int j=1;j<=k;j++){
	// 		dp[i][j]=dp[i-1][j-1]*5ll%mod;
	// 		res+=dp[i-1][j-1];
	// 		res%=mod;
	// 	}
	// 	res+=dp[i-1][k];
	// 	res%=mod;
	// 	dp[i][0]=res*21ll%mod;
	// }
	// int ans=0;
	// for(int i=0;i<=k;i++){
	// 	ans+=dp[n][i];
	// 	ans%=mod;
	// }
	// cout<<ans<<'\n';
	vector<int> ans(n+10);
	ans[0]=1;
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]*26ll%mod;
		int res=0;
		if(i-k-1>=0){
			if(i-1-k==0){
				res=qmi(5,k+1)%mod;
			}
			else{
				res=ans[i-1-k-1]*21ll%mod;
				res=res*(qmi(5,k+1))%mod;
			}
			ans[i]=(ans[i]-res+mod)%mod;
		}
	}
	cout<<ans[n]<<'\n';
}

/*

651
16401
412776
10390401
261539901


885915424
530337981
329544967
26
733867795
*/

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