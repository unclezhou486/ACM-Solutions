#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	if(n<m){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		vector<vector<int> > ans(2*(n+10),vector<int> (m+10));
		for(int i=1;i<=n;i++){
			for(int j=i;j<=m;j++){
				ans[i][j]=i;
			}
			for(int j=i;j<=2*n;j++){
				ans[j][i]=i;
			}
		}
		for(int i=1;i<=2*n;i++){
			for(int j=1;j<=m;j++){
				cout<<ans[i][j]<<" \n"[j==m];
			}
		}
	}
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