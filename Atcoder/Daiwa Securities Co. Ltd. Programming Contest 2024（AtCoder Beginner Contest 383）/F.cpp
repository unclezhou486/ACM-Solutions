#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int p,u,c;
	bool operator<(const node &a) const{
		return c<a.c;
	}
};

void solve(){
	int n,x,k;
	cin>>n>>x>>k;
	vector<node> a(n);
	vector<vector<long long> >dp(x+10,vector<long long>(n+10,-1));
	for(int i=0;i<n;i++){
		int p,u,c;
		cin>>p>>u>>c;
		a[i]={p,u,c};
	}
	dp[0][0]=0;
	sort(a.begin(),a.end());
	int idx=1;
	for(int i=0;i<n;i++){
		for(int j=x;j>=a[i].p;j--){
			if(dp[j-a[i].p][idx]!=-1){
				dp[j][idx]=max(dp[j][idx],dp[j-a[i].p][idx]+a[i].u);
			}
			if(dp[j-a[i].p][idx-1]!=-1){
				dp[j][idx]=max(dp[j][idx],dp[j-a[i].p][idx-1]+a[i].u+k);
			}
		}
		for(int j=0;j<=x;j++){
			dp[j][idx]=max(dp[j][idx],dp[j][idx-1]);
		}
		if(i<n-1&&a[i].c!=a[i+1].c){
			idx+=1;
		}
	}
	long long ans=0;
	for(int i=0;i<=x;i++){
		ans=max(ans,dp[i][idx]);
	}
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}