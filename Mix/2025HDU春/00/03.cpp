#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	long long a=0,b=0,c=0;
	long long x;
	for(int i=1;i<=n;i++){
		cin>>x;
		a+=x;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		b+=x;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		c+=x;
	}
	cout<<(c-b)/a<<'\n';
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