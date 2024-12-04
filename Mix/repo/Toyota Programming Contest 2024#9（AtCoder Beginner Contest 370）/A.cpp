#include <bits/stdc++.h>

using namespace std;

int l,r;

void solve(){
	cin>>l>>r;
	if(l&&!r){
		cout<<"Yes\n";
	}
	else if(!l&&r){
		cout<<"No\n";
	}
	else{
		cout<<"Invalid\n";
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