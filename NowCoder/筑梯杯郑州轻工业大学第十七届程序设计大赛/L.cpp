#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long N,M,n,m;
	cin>>N>>M>>n>>m;
	long long x=(N-n);
	long long y=(M-m);
	long long ans=0;
	ans=gcd(ans,x);
	ans=gcd(ans,y);
	ans=gcd(ans,M);
	ans=gcd(ans,N);
	ans=gcd(ans,n);
	ans=gcd(ans,m);
	cout<<ans<<'\n';
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