#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	map<int,int> ma;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma[a[i]]=i;
	}
	vector<pair<int,int> > vec;
	for(auto [aa,bb]:ma){
		vec.push_back({bb,aa});
		if(vec.size()==3){
			break;
		}
	}
	sort(vec.begin(),vec.end());
	for(auto [x,y]:vec){
		cout<<y<<" ";
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