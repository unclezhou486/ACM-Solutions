#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	map<int,int> ma;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ma[x]+=1;
	}
	int ans=-1;
	for(auto [a,b]:ma){
		if(a%2==0&&b%2){
			ans=max(ans,a);
		}
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