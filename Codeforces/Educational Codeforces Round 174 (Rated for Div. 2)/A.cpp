#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	n-=2;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=1;
	for(int i=2;i<=n-1;i++){
		if(a[i-1]==1&&a[i]==0&&a[i+1]==1){
			flag=0;
		}
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