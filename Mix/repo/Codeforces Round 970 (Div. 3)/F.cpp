#include <bits/stdc++.h>

using namespace std;

constexpr int MOD=1e9+7;
constexpr int N=2e5+10;

long long qmi(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res;
}

long long inv(long long x){
	return qmi(x,MOD-2);
}

int n;
long long a[N];
void solve(){
	cin>>n;
	long long cnt,sum,ans;
	cnt=sum=ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=sum*a[i];
		sum+=a[i];
		sum%=MOD;
		ans%=MOD;
		cnt+=i-1;
		cnt%=MOD;
	}
	cout<<ans*inv(cnt)%MOD<<'\n';
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