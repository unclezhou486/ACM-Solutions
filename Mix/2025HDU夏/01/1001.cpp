#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

int mi[1000010];
int ni[1000010];

long long qmi(long long a,long long b){
	long long res=1;
	a%=mod;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

long long inv(long long x){
	return qmi(x,mod-2);
}

void init(){
	mi[0]=1;
	for(int i=1;i<=1000000;i++){
		mi[i]=1ll*mi[i-1]*i%mod;
	}
	ni[1000000]=inv(mi[1000000]);
	for(int i=1000000-1;i>=1;i--){
		ni[i]=1ll*ni[i+1]*(i+1)%mod;
	}
	ni[0]=1;
}

int A(int n,int m){
	return 1ll*mi[n]*ni[n-m]%mod;
}

void solve(){
	int n;
	cin>>n;
	int odd,even,m1,m0;
	odd=even=m1=m0=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int res=0;
		bool flag=true;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			res^=x;
			if(x!=1){
				flag=false;
			}
		}
		if(flag==true){
			k%2?odd++:even++;
		}
		else{
			res?m1++:m0++;
		}
	}
	if(odd+even==n){
		if(odd%2) cout<<mi[n]<<'\n';
		else cout<<0<<'\n';
	}
	else{
		int ans=0;
		int res=0;
		for(int i=1;i<=odd;i+=2){
			res=(res+1ll*A(odd,i)*mi[m1+m0+odd-i-1]%mod)%mod;
		}
		res=1ll*res*m0%mod*A(n,even)%mod;
		ans=(res+ans)%mod,res=0;
		for(int i=0;i<=odd;i+=2){
			res=(res+1ll*A(odd,i)*mi[m0+m1+odd-i-1]%mod)%mod;
		}
		res=1ll*res*m1%mod*A(n,even)%mod;
		ans=(ans+res)%mod;
		cout<<ans<<'\n';
	}
}

int main(){
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}