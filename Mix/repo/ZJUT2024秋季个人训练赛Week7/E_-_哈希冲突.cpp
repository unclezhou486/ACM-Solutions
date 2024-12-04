#include <bits/stdc++.h>

using namespace std;

constexpr int M=400;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<long long > a(n+10);
	vector<vector<long long> > pre(410,vector<long long >(410,0));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=M;j++){
			pre[j][i%j]+=a[i];
		}
	}
	for(int i=1;i<=m;i++){
		char op;
		int x,y;
		cin>>op>>x>>y;
		if(op=='A'){
			if(x<=M){
				cout<<pre[x][y]<<'\n';
			}
			else{
				long long ans=0;
				for(int i=y;i<=n;i+=x){
					ans+=a[i];
				}
				cout<<ans<<'\n';
			}
		}
		else{
			for(int j=1;j<=M;j++){
				pre[j][x%j]-=a[x];
			}
			a[x]=y;
			for(int j=1;j<=M;j++){
				pre[j][x%j]+=a[x];
			}
		}
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