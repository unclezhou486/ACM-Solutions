#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	map<int,int> ma;
	for(int i=1;i<=n;i++) cin>>a[i],ma[a[i]]+=1;
	vector<int> ans;
	for(auto [x,y]:ma){
		if(y==1){
			ans.push_back(x);
		}
	}
	for(auto x:ans){
		cout<<x<<" ";
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