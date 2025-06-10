#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,l;
	cin>>n>>l;
	vector<int> a(l);
	int idnow=0;
	a[idnow]+=1;
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		idnow=(idnow+x)%l;
		a[idnow]+=1;
	}
	if(l%3){
		cout<<0<<'\n';
		return;
	}
	long long ans=0;
	for(int i=0;i<l/3;i++){
		ans+=1ll*a[i]*a[i+l/3]*a[i+l/3*2];
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