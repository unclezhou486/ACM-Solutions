#include <bits/stdc++.h>

using namespace std;

constexpr int mod=998244353;

int a[40];

int b[40];

int dp[40];
int len=0;

int dfs(int u,bool lim){
	if(u==0){
		return 1;
	}
	if(!lim&&dp[u]!=-1) return dp[u];
	int cnt=0;
	int lst=lim?b[u]:1;
	for(int i=0;i<=lst;i++){
		// if(f0&&i==0){
		// 	cnt+=dfs(u-1,1,lim&&i==lst);
		// }
		// else{
		// 	cnt
		// }
		if(a[u]==0&&i==1) continue;
		cnt+=dfs(u-1,lim&&i==lst);
	}
	if((!lim)) dp[u]=cnt;
	return cnt;
}

void cal(int x){
	len=0;
	while(x){
		a[++len]=x%2;
		x/=2;
	}
	// for(int i=0;i<=30;i++){
	// 	a[i]=x%2;
	// 	x/=2;
	// }
}

int sol(int x){
	for(int i=1;i<=len;i++){
		b[i]=x%2;
		x/=2;
		dp[i]=-1;
	}
	return dfs(len,1);
}

void solve(){
	int n;
	cin>>n;
	vector<int> c(n+10);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}	
	long long ans=1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cal(c[i]);
		long long res=sol(min(x,c[i]));
		// cout<<res<<'\n';
		ans*=res;
		ans%=mod;
	}
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