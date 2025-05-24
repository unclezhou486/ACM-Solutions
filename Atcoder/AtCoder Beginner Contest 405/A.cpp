#include<bits/stdc++.h>

using namespace std;

void solve(){
	int r,x;
	cin>>r>>x;
	if(x==1){
		if(1600<=r&&r<=2999){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	else{
		if(1200<=r&&r<=2399){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
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
