#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

bool Be;


bool Ed;

void solve(){
	cout<<((&Be-&Ed))<<'\n';	
	cout<<((&Be-&Ed)>>10)<<'\n';	
	cout<<((&Be-&Ed)>>20)<<'\n';	
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