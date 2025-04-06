#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

long long qmi(long long a,long long b,long long MOD){
	long long res=1;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

void solve(){
	int n;
	cin>>n;
	vector<int> p(n+10),e(n+10);
	
	for(int i=1;i<=n;i++){
		cin>>p[i]>>e[i];

	}
	int b;
	cin>>b;
	long long ans=1;
	long long resans=1;
	for(int i=1;i<=n;i++){
		long long res=qmi(p[i],e[i],mod);
		long long ress=qmi(p[i],e[i],b);
		ans*=res;
		ans%=mod;
		resans*=ress;
		resans%=b;
	}
	ans=(ans-resans+mod)%mod;
	ans=ans*qmi(b,mod-2,mod)%mod;
	cout<<ans<<'\n';

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