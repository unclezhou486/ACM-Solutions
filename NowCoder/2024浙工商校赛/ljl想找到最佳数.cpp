#include <bits/stdc++.h>

using namespace std;


void solve(){
	int n,k;
	cin>>n>>k;
	map<int,int> ma;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ma[x]+=1;
	}
	int ans=-1;
	for(auto [x,y]:ma){
		if(y==k){
			ans=max(ans,x);
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