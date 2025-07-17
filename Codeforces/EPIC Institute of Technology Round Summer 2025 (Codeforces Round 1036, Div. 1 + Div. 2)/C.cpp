// x*y^0 a*y^0   ab*y^1   abc*y^0
//a*y  b
//gcd(x1,x2)
//a
//x1/gcd(x1,x2)

#include <bits/stdc++.h>

using namespace std;

int lcm(int x,int y){
	return 1ll*x/gcd(x,y)*y;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=1;i<n;i++){
		if(a[i]%a[i-1]){
			int y=a[i-1]/gcd(a[i-1],a[i]);
			ans=lcm(ans,y);
		}
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