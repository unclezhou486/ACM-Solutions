#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	for(int i=3;i<s.size();i++){
		if(s[i-3]=='2'&&s[i-2]=='0'&&s[i-1]=='2'&&s[i]=='4'){
			s[i]='5';
		}
	}
	cout<<s<<'\n';
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