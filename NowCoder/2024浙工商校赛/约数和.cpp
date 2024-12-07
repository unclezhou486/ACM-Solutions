#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod=998244353;

int sol(int x){
	long long res=0;
	int id=1;
	while(id<=x){
		int l=id,r=x;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(x/id==x/mid){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		int a=id,b=l;
		// cout<<a<<' '<<b<<'\n';
		id=l+1;
		long long ress=0;
		ress=(x/a*(a+b)*(b-a+1)/2)%mod;
		res+=ress;
		res%=mod;
	}
	return res;
}

void solve(){
	int n,m;
	cin>>n>>m;
	cout<<(sol(m)-sol(n-1)+mod)%mod<<'\n';
}

signed main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}