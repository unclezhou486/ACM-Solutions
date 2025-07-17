#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(2*n+10);
	multiset<int> se1,se2;
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		se1.insert(a[i]);
	}
	se2=se1;
	int x=*se2.rbegin();
	se2.extract(x);
	for(auto y:se1){
		int res=x+y;
		vector<pair<int,int> > ans;
		se2=se1;
		int resx=x;
		while(se2.size()){
			int resy=res-resx;
			se2.extract(resx);
			if(se2.count(resy)){
				ans.emplace_back(resx,resy);
				se2.extract(resy);
				res=max(resy,resx);
				if(se2.size())resx=*se2.rbegin();
			}
			else{
				break;
			}
		}
		if(!se2.size()){
			cout<<"YES\n";
			cout<<ans[0].first+ans[0].second<<'\n';
			for(auto [x,y]:ans){
				cout<<x<<' '<<y<<'\n';
			}
			return;
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