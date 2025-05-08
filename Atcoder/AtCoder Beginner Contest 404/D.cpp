#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> c(n+10);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	vector<vector<int> > a(m+10,vector<int>(n+10) );
	vector<vector<int> > an(n+10);
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			an[x].push_back(i);
		}
	}
	long long ans=1e18;
	int limit=pow(3,n)-1;
	for(int i=0;i<=limit;i++){
		long long res=0;
		int x=i;
		vector<int> cnt(m+10);
		for(int j=1;j<=n;j++){
			int count=x%3;
			res+=c[j]*count;
			if(count){
				for(auto y:an[j]){
					cnt[y]+=count;
				}
			}
			x/=3;
		}
		bool flag=true;
		for(int j=1;j<=m;j++){
			if(cnt[j]<2){
				flag=false;
				break;
			}
		}
		if(flag){
			// cout<<i<<'\n';
			ans=min(ans,res);
		}
	}
	cout<<ans<<'\n';
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