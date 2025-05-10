#include <bits/stdc++.h>

using namespace std;

void solve(){
	double v0,a,v1,t;
	cin>>v0>>a>>v1>>t;
	double res=min((v1-v0)/a,t);
	double ans=v0*res+0.5*a*res*res;
	t-=res;
	ans+=t*v1;
	cout<<fixed<<setprecision(3)<<ans<<'\n';
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