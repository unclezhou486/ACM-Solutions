#include <bits/stdc++.h>

using namespace std;

void solve(){
	int x;
	cin>>x;
	if(x%33==0){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
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