#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e5+10;
constexpr int M=1e5;
constexpr int MOD=998244353;

int n,m;

vector<int> son[N];

int jc[N];
int iv[N];
int dp[N][50];

int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return res;
}

int inv(int x){
	return qmi(x,MOD-2);
}

int C(int n,int m){
	if(n<m) return 0;
	if(!m) return 1;
	return 1ll*jc[n]%MOD*iv[m]%MOD*iv[n-m]%MOD;
}

void table(){
	jc[0]=1;
	for(int i=1;i<=M;i++){
		jc[i]=1ll*i*jc[i-1]%MOD;
	}
	iv[M]=inv(jc[M]);
	for(int i=M-1;i>=0;i--){
		iv[i]=1ll*iv[i+1]*(i+1)%MOD;
	}
	for(int i=1;i<=M;i++){
		for(int j=i;j<=M;j+=i){
			son[j].push_back(i);
		}
	}
}

void solve(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		reverse(son[i].begin(),son[i].end());
		for(auto x:son[i]){
			// if(x==i) continue;
			for(int j=49;j>=2;j--){
				dp[i][j]=(dp[i][j]+dp[x][j-1])%MOD;
			}	
		}
		dp[i][1]=1;
	}
	int ans=1ll*n*C(m,n)%MOD;
	// cout<<ans<<'\n';
	int res=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<50;j++){
			if(!dp[i][j]) continue;
			res=(res+(1ll*dp[i][j]*C(m/i-1,n-j)%MOD))%MOD;
		}
	}
	ans=(MOD+ans-res)%MOD;
	cout<<ans<<'\n';
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	table();
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


/*



*/