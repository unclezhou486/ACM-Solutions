#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+10);
	int idx=0;
	vector<int> vis(n+10);
	for(int i=k;i<=n;i+=k){
		a[i]=++idx;
	}
	for(int i=1;i<=n;i++){
		if(!a[i]){
			a[i]=++idx;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" \n"[i==n];
	}
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