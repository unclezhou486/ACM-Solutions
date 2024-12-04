#include <iostream>
#include <algorithm>

using namespace std;

long long n,k;

long long check(long long x){
	long long res=(k+x)*(x-k+1)/2-(x+1+n+k-1)*(k+n-1-(x+1)+1)/2;
	return abs(res);
}

void solve(){
	cin>>n>>k;
	long long l=k,r=k+n-1;
	while(r-l>=10){
		long long mid1=l+(r-l)/3;
		long long mid2=r-(r-l)/3;
		long long x=check(mid1),y=check(mid2);
		if(x<y) r=mid2;
		else l=mid1;
	}
	long long ans=1e18;
	for(int i=l;i<=r;i++){
		ans=min(ans,check(i));
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