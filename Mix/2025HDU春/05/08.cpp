#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20){
		cout<<"YES\n";
	}
	else{
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				
			}
		}
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