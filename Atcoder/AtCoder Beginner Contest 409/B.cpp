#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	sort(a.begin(),a.end());
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r+1)>>1;
		int cnt=n-(lower_bound(a.begin(),a.end(),mid)-a.begin());
		if(cnt>=mid) l=mid;
		else r=mid-1;
	}
	cout<<l<<'\n';
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