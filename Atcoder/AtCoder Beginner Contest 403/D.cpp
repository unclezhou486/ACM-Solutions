#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,d;
	cin>>n>>d;
	vector<vector<int> > vec(d);
	vector<int> cnt(1000010);
	if(!d){
		int ans=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(cnt[x]){
				ans++;
			}
			cnt[x]++;
		}
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		vec[x%d].push_back(x);
		cnt[x]+=1;
	}
	int ans=0;
	for(int i=0;i<d;i++){
		sort(vec[i].begin(),vec[i].end());
		int m=unique(vec[i].begin(),vec[i].end())-vec[i].begin();
		// int m=vec[i].size();
		// cout<<m<<'\n';
		if(!m) continue;
		vector<vector<int> > dp(m,vector<int>(2));
		dp[0][0]=cnt[vec[i][0]];
		for(int j=1;j<m;j++){
			if(vec[i][j]-vec[i][j-1]==d){
				dp[j][1]=dp[j-1][0];
			}
			else{
				dp[j][1]=min(dp[j-1][0],dp[j-1][1]);
			}
			dp[j][0]=min(dp[j-1][1],dp[j-1][0])+cnt[vec[i][j]];
		}
		ans+=min(dp[m-1][0],dp[m-1][1]);
	}
	cout<<ans<<'\n';
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
