#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

void solve(){
	long long n;
	cin>>n;
	if(n==1){
		cout<<0<<'\n';
		return;
	}
	long long ans=0;
	long long r=n;
	if(r%2) r-=1;
	long long l=2;
	cout<<((l+r)*(n/2)/2)%mod<<'\n';
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