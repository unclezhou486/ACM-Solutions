#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

constexpr int N=2e5+10;

long long mi[N];

long long ni[N];

long long qmi(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans1=0,ans2=1;
	int inv2=qmi(2,mod-2);
	for(int i=2;i<=n;i++){
		ans1+=(1ll*a[i]*a[i-1]%mod);
		ans1%=mod;
		a[i]+=a[i-1];
		a[i]%=mod;
	}
	for(int i=2;i<=n;i++){
		ans2=(ans2*(i)%mod)*(i-1)%mod;
		ans2=ans2*inv2%mod;
	}
	if(n==1){
		ans2=0;
	}
	cout<<ans1<<' '<<ans2<<'\n';
}
//n*(n-1)/2+(n-1)*(n-2)+...+(2*1)/2;

int main(){
	mi[0]=1;
	for(int i=1;i<=200000;i++){
		mi[i]=1ll*mi[i-1]*i%mod;
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}