#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long a,b,k;
	cin>>a>>b>>k;
	long long gd=gcd(a,b);
	if(max(a/gd,b/gd)<=k){
		cout<<1<<'\n';
	}
	else{
		cout<<2<<'\n';
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
