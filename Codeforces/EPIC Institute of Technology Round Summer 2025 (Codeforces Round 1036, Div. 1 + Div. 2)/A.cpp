#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(i){
			if(a[i]<a[i-1]){
				cout<<"YES\n";
				cout<<2<<'\n';
				cout<<a[i-1]<<' '<<a[i]<<'\n';
				return;
			}
		}		
	}
	cout<<"NO\n";
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