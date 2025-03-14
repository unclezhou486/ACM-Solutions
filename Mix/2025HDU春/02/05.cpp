#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n,k;
	cin>>n>>k;
	if(k%2){
		cout<<0<<'\n';
		return;
	}
	long long ans=0;
	long long res=(n-1-k/2);
	if(n>k/2){
		ans=n-k/2;
		long long x=res/k;
		ans+=((x)*(x-1)/2)*k;
		long long y=x*k;
		ans+=(res-y+1)*x;
	}
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