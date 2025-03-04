#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	vector<vector<long long> > maxn(1024,vector<long long>(1024,-1e18));
	vector<long long> dp(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}	
	dp[0]=0;
	for(int j=0;j<1024;j++){
		maxn[0][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<1024;j++){
			dp[i]=max(dp[i],maxn[j][a[i]]+i*(j^a[i]));
		}
		for(int j=0;j<1024;j++){
			maxn[a[i]][j]=max(maxn[a[i]][j],dp[i]-i*(a[i]^j));
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i];
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
