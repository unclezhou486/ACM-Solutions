#pragma GCC O(2)
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

int a[N];

void solve(){
	int n;
	cin>>n;
	int res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		res+=a[i];
	}
    sort(a+1,a+1+n);
    int resss=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int ress=res-a[i];
		ress+=a[i]*(n-1);
//		cout<<ress<<' ';
		ress+=(i-1)*a[i]-resss;
//		cout<<ress<<' ';
//		cout<<poss.first<<' '<<pos.first<<' '<<poss.second<<" "<<pos.second<<'\n';
		ress+=res-resss-(n-(i-1))*a[i];
		ans+=ress;
        resss+=a[i];
//		cout<<ress<<'\n';
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