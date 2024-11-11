#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=5;
	// cin>>t;
	mt19937 myrand(clock());
	cout<<t<<'\n';
	int m=10;
	while(t--){
		// solve();
		int n=myrand()%m+1,k=myrand()%n+1;
		cout<<n<<' '<<k<<'\n';
		for(int i=1;i<=n;i++){
			long long x=myrand()%100;
			int y;
			if(x%2) y=-1;
			else y=1;
			// cout<<"X:"<<x<<' '<<"Y:"<<y<<'\n';
			cout<<x*y<<" \n"[i==n];
		}
	}
	return 0;
}