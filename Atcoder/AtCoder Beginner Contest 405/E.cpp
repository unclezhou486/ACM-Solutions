#include<bits/stdc++.h>

using namespace std;

constexpr int mod=998244353;

long long qmi(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

long long inv(long long x){
	return qmi(x,mod-2);
}

void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int maxn=max({a,b,c,d})*2;
	vector<int> jie(maxn+10);
	jie[0]=1;
	for(int i=1;i<=maxn;i++){
		jie[i]=1ll*jie[i-1]*i%mod;
		// cout<<jie[i]<<" \n"[i==maxn];
	}
	auto A = [&](int n,int m) -> int {
		return 1ll*jie[n]*inv(jie[m])%mod*inv(jie[n-m])%mod;
	};
	cout<<1ll*A(a+b+c,a)*A(c+d,c)%mod<<'\n';
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
