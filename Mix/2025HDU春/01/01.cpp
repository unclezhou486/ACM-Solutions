#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	string str;
	cin>>n>>str;
	int ans=-1;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s==str){
			ans=i;
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