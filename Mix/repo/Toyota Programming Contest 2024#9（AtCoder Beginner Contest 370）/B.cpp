#include <bits/stdc++.h>

using namespace std;

const int N=1e2+10;

int n,a[N][N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	int res=1;
	for(int i=1;i<=n;i++){
		int x=res,y=i;
		if(x<y) swap(x,y);
		res=a[x][y];
	}
	cout<<res<<'\n';
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