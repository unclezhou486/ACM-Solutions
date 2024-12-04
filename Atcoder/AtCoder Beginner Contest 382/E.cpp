#include <bits/stdc++.h>
#define double long double 
using namespace std;

void solve(){
	int n,x;
	cin>>n>>x;
	vector<double> dp(n+10,0);
	vector<double> f(x+10,0);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		double a;
		cin>>a;
		a=a/100;
		for(int j=n;j>=1;j--){
			dp[j]=dp[j]*(1.0-a)+dp[j-1]*a;
		}
		dp[0]=dp[0]*(1.0-a);
	}
	// for(int i=1;i<=n;i++){
		// cout<<fixed<<setprecision(10);
		// cout<<dp[i]<<" \n"[i==n];
	// }
	for(int i=1;i<=x;i++){
		double res=0;
		for(int j=0;j<i;j++){
			if(i-j>n) continue;
			res+=f[j]*dp[i-j];
		}
		res+=1;
		res/=(1-dp[0]);
		f[i]=res;
	}
	cout<<fixed<<setprecision(16);
	cout<<f[x]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}