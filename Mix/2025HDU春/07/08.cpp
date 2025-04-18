#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	long long ans=1ll*a*b*c;
	ans=ans*(d*(d-1)/2)+ans*d*e;
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