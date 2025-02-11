#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	// int res=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(((i-1)*2>=a[i]||(n-i)*2>=a[i])) flag=false;
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
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