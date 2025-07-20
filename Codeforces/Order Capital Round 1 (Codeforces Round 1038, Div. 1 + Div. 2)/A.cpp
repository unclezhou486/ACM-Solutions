#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	if(n==1||m==1||(n==2&&m==2)){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
	}
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
