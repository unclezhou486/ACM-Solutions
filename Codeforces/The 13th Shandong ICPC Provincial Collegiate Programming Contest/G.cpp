#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	map<int,vector<int> > ma;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma[a[i]-i].push_back(a[i]);
	}
	long long ans=0;
	for(auto [x,vec]:ma){
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		for(int i=0;i+1<vec.size();i+=2){
			if(vec[i]+vec[i+1]<=0) break;
			ans+=vec[i]+vec[i+1];
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