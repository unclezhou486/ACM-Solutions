#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	set<char> se;
	for(auto ch:s){
		se.insert(ch);
	}	
	for(char i='a';i<='z';i++){
		if(!se.count(i)){
			cout<<i<<'\n';
			return;
		}
	}
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