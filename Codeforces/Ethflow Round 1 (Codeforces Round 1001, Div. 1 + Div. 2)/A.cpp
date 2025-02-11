#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	int ans=0;
	for(auto x:s){
		if(x=='1') ans+=1;
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