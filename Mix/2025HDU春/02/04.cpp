#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s,kk;
	int k=0;
	cin>>s>>kk;
	if(kk.size()>2){
		k=26;
	}
	else{
		for(int i=0;i<kk.size();i++){
			k=k*10+(kk[i]-'0');
		}
	}
	string res="";
	for(int i=1;i<=k;i++){
		res=res+s;
	}
	vector<int> dp(30,0);
	for(int i=0;i<res.size();i++){
		int x=res[i]-'a';
		dp[x]=max(dp[x],1);
		for(int j=0;j<x;j++){
			dp[x]=max(dp[x],dp[j]+1);
		}
	}
	int ans=0;
	for(int i=0;i<26;i++){
		ans=max(ans,dp[i]);
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