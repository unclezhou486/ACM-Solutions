#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> app(m+10);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(!app[x]){
			app[x]=i;
		}
	}
	int ans=n;
	for(int i=1;i<=m;i++){
		if(!app[i]){
			ans=0;
			break;
		}
		else{
			ans=min(ans,n-app[i]+1);
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
