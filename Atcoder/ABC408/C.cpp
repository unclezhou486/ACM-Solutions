#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+10);
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		a[l]+=1,a[r+1]-=1;
	}
	int ans=m;
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
		ans=min(ans,a[i]);
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