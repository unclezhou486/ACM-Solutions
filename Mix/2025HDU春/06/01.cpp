#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long k,a[4];
	cin>>k>>a[0]>>a[1]>>a[2];
	long long ans=k;
	for(int i=0;i<(1<<3);i++){
		long long res=0;
		for(int j=0;j<3;j++){
			if((i>>j)&1) res+=a[j];
		}
		if(res<=k){
			ans=min(ans,k-res);
		}
	}
	cout<<ans<<'\n';

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