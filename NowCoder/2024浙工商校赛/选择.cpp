#include <bits/stdc++.h>

using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+1+n);
	int ans=0;
	//1... n-i+1
	for(int i=n;i>=1;i--){
		ans=max(ans,n-i+1+a[i+(n-i+2)/2-1]);
	}
	cout<<ans<<'\n';
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