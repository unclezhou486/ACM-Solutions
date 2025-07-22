#include<bits/stdc++.h>

using namespace std;

constexpr int mod=998244353;

long long qmi(long long a,long long b){
	long long res=1;
	a%=mod;
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

struct line{
	long long l,r,p;
	bool operator<(const line &a) const{
		return l<a.l;
	}
};



void solve(){
	int n,m;
	cin>>n>>m;
	vector<line> a(n);
	vector<long long> dp(m+10);
	vector<long long> pre(m+10,1);
	dp[0]=1;
	for(int i=0;i<n;i++){
		long long p,q;
		cin>>a[i].l>>a[i].r>>p>>q;
		a[i].p=(p*inv(q))%mod;
		pre[a[i].l]*=(1-a[i].p+mod)%mod;
        pre[a[i].l]%=mod;
    }
	for(int i=1;i<=m;i++){
		pre[i]=pre[i-1]*pre[i]%mod;
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		auto [l,r,p]=a[i];
		long long res=pre[r]*inv(pre[l-1])%mod;
		res=res*inv(1-p+mod)%mod;
		dp[r]+=dp[l-1]*res%mod*p%mod;
		dp[r]%=mod;
	}
	// for(int i=1;i<=m;i++){
	// 	cout<<dp[i]<<'\n';
	// }
	cout<<dp[m]<<'\n';
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
