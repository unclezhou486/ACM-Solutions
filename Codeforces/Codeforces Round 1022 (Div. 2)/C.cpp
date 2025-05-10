#include <bits/stdc++.h>

using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m=unique(a.begin()+1,a.begin()+1+n)-(a.begin()+1);
	int ans=0;
	a[m+1]=0;
	for(int i=1;i<=m;i++){
		// cout<<a[i]<<" \n"[i==m];
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			ans++;
		}
	}
	cout<<ans<<'\n';
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