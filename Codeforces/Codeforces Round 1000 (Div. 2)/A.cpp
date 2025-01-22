#include <bits/stdc++.h>

using namespace std;

void solve(){
	int l,r;
	cin>>l>>r;
	if(l==r&&l==1) cout<<1<<'\n';
	else cout<<r-l<<'\n';
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