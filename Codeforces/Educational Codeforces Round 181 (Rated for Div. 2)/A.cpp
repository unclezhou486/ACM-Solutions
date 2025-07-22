#include<bits/stdc++.h>

using namespace std;

//NTNTT
//TNTNT

//FFT
//FTF

void solve(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
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
