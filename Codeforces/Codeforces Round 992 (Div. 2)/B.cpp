#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	int x=1;
	int ans=1;
	while(x<n){
		x=(x+1)*2;
		ans++;
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