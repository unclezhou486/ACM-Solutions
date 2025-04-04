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

constexpr int N=5e5+10;

long long mi[N],ni[N];

void solve(){
	vector<int> a(30);
	int sum=0;
	for(int i=1;i<=26;i++){
		cin>>a[i];
		sum+=a[i];
	}
	// if(sum%2){
	// 	cout<<0<<'\n';
	// 	return;
	// }
	vector<int> dp(sum+10);
	vector<int> ans(sum+10);
	dp[0]=1;
	ans[0]=1;
	int res=1;
	for(int i=1;i<=26;i++){
		if(!a[i]) continue;
		for(int j=sum/2;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			// ans[j]=ans[j]+(1ll*ans[j-a[i]]*ni[a[i]]%mod);
			dp[j]%=mod;
			// ans[j]%=mod;
		}
		res=1ll*res*ni[a[i]]%mod;
	}
	// cout<<ans[sum/2]<<" "<<dp[sum/2]<<' '<<sum/2<<'\n';
	// int anss=1ll*ans[sum/2]*mi[sum/2]%mod<<'\n';
	int anss=1ll*mi[sum/2]*mi[sum-sum/2]%mod;
	anss=1ll*anss*dp[sum/2]%mod;
	anss=1ll*anss*res%mod;
	cout<<anss<<'\n';
	// cout<<1ll*ans[sum/2]*
}

int main(){
	mi[0]=1;
	for(int i=1;i<=500000;i++){
		mi[i]=1ll*mi[i-1]*i%mod;
	}
	ni[500000]=inv(mi[500000]);
	for(int i=500000-1;i>=1;i--){
		ni[i]=(1ll*ni[i+1]*(i+1))%mod;
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
