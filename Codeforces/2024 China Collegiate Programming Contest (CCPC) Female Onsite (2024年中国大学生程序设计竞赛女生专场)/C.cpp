#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	int cntc=0,cntp=0;
	for(auto x:s){
		if(x=='C') cntc+=1;
		else if(x=='P') cntp+=1;
	}
	int res=(cntc-1)/2;
	cout<<min(res,cntp)<<'\n';
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