#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod=998244353;

long long qmi(long long a,long long b){
	a%=mod;
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

long long inv(long long x){
	return qmi(x,mod-2);
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> p(k+10);
	long long ans=1;
	for(int i=0;i<=k;i++){	
		cin>>p[i];
		p[i]-=1;
	}
	sort(p.begin()+1,p.begin()+1+k);
	for(int i=0;i<=30;i++){
		int l,r;
		if((p[0]>>i)&1){
			l=((p[0]>>i)<<i);
			r=l+(1ll<<i)-1;
		}
		else{
			l=(((p[0])>>i)<<i)+(1ll<<i);
			r=l+(1ll<<i)-1;
		}
		// l=min(l,n);
		// r=min(r,n);
		int idr=upper_bound(p.begin()+1,p.begin()+1+k,r)-p.begin()-1;
		idr-=1;
		int idl=lower_bound(p.begin()+1,p.begin()+1+k,l)-p.begin()-1;
		int cnt=0;
		if(idl<=idr){
			cnt=idr-idl+1;
		}
		int len=r-l+1;
		cnt=len-cnt;
		ans=ans*cnt%mod;
		ans=ans*inv(len)%mod;
	}
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// cout<<(1<<30)<<'\n';
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}