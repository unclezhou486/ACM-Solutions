#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

int a[N];

void solve(){
	int n;
	cin>>n;
	int res=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=min(4*(a[1]),2*a[i])*(n-i);
		ans+=res;
		res+=min(2*a[i],4*a[1]);
	}
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}	
	return 0;
}