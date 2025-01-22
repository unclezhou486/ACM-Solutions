#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	int a=0,b=0;
	int x,y;
	cin>>x>>y;
	for(int i=2;i<=n;i++){
		// int x,y;
		cin>>x>>y;
		a+=x;
		b+=y;
	}
	cout<<2*(a+m+b+m)<<'\n';
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