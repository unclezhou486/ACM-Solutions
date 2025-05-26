#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> cnt(n+10);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]+=1;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j+i<=n;j+=i){
			ans+=cnt[j]*cnt[j+i];
		}
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