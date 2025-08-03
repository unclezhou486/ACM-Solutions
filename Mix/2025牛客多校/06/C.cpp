#include <bits/stdc++.h>

using namespace std;

//(x+1)^3=n*(x^3)+3(x^2)+3(x)+cnt

//(x+1)^2=n*x^2+2*x+cnt

//27+8+8+1+8+1=

//3*(9)+3*(5)+9+1=27+15+10=

//2*1+3*1+3*1+1=2+3+3+1=9

constexpr int N=5e5+10;
constexpr int mod=998244353;

int cnt[N],sum1[N],sum2[N],sum3[N];
void init(){
	cnt[1]=sum1[1]=sum2[1]=sum3[1]=1;
	for(int i=2;i<=N-10;i++){
		sum3[i]=(1ll*i*(sum3[i-1])%mod+1ll*3*sum2[i-1]%mod+1ll*3*sum1[i-1]%mod+cnt[i-1])%mod;
		sum2[i]=(1ll*i*sum2[i-1]%mod+1ll*2*sum1[i-1]%mod+cnt[i-1])%mod;
		sum1[i]=(1ll*i*sum1[i-1]%mod+cnt[i-1])%mod;
		cnt[i]=1ll*i*cnt[i-1]%mod;
	}
}

void solve() {
	int x;
	cin>>x;
	cout<<sum3[x]<<'\n';
}

int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}