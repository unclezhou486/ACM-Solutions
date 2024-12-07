#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e6+10;

bool dp[N][3];

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	s='#'+s;
	for(int i=0;i<3;i++){
		dp[0][i]=1;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='A'){
			dp[i][0]=dp[i-1][1]|dp[i-1][2];
		}
		else if(s[i]=='B'){
			dp[i][1]=dp[i-1][0]|dp[i-1][2];
		}
		else if(s[i]=='C'){
			dp[i][2]=dp[i-1][0]|dp[i-1][1];
		}
		else{
			dp[i][0]=dp[i-1][1]|dp[i-1][2];
			dp[i][1]=dp[i-1][0]|dp[i-1][2];
			dp[i][2]=dp[i-1][0]|dp[i-1][1];
		}
	}
	bool flag=false;
	for(int i=0;i<3;i++){
		flag|=dp[n][i];
	}
	if(!flag){
		cout<<-1<<'\n';
		return;
	}
	int i=n;
	// string ans="";
	vector<char> ans;
	while(i>=1){
		for(int j=0;j<3;j++){
			if(dp[i][j]&&(!ans.size()||ans[ans.size()-1]!='A'+j)){
				char ch='A'+j;
				// ans=ch+ans;
				ans.push_back(ch);
				break;
			}
		}
		i--;
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans){
		cout<<x;
	}
	// cout<<ans<<'\n';
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