#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<pair<int,string>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].second;
		a[i].first=a[i].second.size();
	}
	sort(a.begin(),a.end());
	for(auto [x,y]:a){
		cout<<y;
	}
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
