#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<int> >a(n+10,vector<int> (n+10));
	int idx=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			idx++;
			a[i][j]=idx;
			a[j][i]=idx;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" \n"[j==n];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
	return 0;
}