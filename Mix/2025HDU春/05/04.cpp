#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
constexpr ll N=210;

constexpr int mod=998244353;

struct Matrix{
	ll n,m;
	ll a[N][N];

	void set(ll _a,ll _b){
		n=_a,m=_b;
	}

	Matrix(){
		clear();
	}

	void clear(){
		n=m=0;
		memset(a,0,sizeof (a));
	}

	Matrix operator+(const Matrix &b) const {
		Matrix tmp;
		tmp.clear();
		tmp.n=n;
		tmp.m=m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;j++){
				tmp.a[i][j]=a[i][j]+b.a[i][j];
			}
		}
		return tmp;
	}

	Matrix operator*(const Matrix &b) const {
		Matrix tmp;
		tmp.clear();
		tmp.n=n;
		tmp.m=b.m;
		for(ll i=0;i<n;++i){
			for(ll k=0;k<m;++k){
				if(a[i][k]==0) continue;
				for(ll j=0;j<b.m;++j){
					tmp.a[i][j]+=(a[i][k]*b.a[k][j])%mod;
					tmp.a[i][j]%=mod;
				}
			}
		}
		return tmp;
	}

	Matrix get(ll x){
		Matrix E;
		E.clear();
		E.set(n,m);
		for(ll i=0;i<n;++i){
			E.a[i][i]=1;
		}
		while(x){	
			if(x&1){
				E=*this*E;
			}
			*this=*this**this;
			x>>=1;
		}
		return E;
		// if(x==0) return E;
		// else if(x==1) return *this;
		// Matrix tmp = get(x/2);
		// tmp = tmp*tmp;
		// if(x*2) tmp=tmp*(*this);
		// return tmp;
	}

};

void solve(){
	long long n;
	int m;
	cin>>n>>m;
	long long res=n/m;
	vector<long long> a(m+10,res);
	vector<long long> dp(m+10),dpp(m+10);
	dp[0]=1;
	Matrix C;
	C.clear();
	C.set(m,m);
	for(ll i=0;i<m;i++){
		C.a[i][i]=1;
	}
	for(int i=0;i<m;i++){
		Matrix B;
		B.clear();
		B.set(m,m);
		for(int j=0;j<m;j++){
			B.a[j][j]=1;
			B.a[(j-i+m)%m][j]+=1;
		}
		C=C*B;
	}
	Matrix A;
	A.clear();
	A.set(1,m);
	A.a[0][0]=1;
	C=C.get(res);
	A=A*C;
	C.clear();
	C.set(m,m);
	for(ll i=0;i<m;i++){
		C.a[i][i]=1;
	}
	for(int i=0;i<n%m;i++){
		// a[i]+=1;
		Matrix B;
		B.clear();
		B.set(m,m);
		for(int j=0;j<m;j++){
			B.a[j][j]=1;
			B.a[(j-i+m)%m][j]+=1;
		}
		C=C*B;
	}
	A=A*C;
	// for(int i=0;i<m;i++){
	// 	Matrix B;
	// 	B.clear();
	// 	B.set(m,m);
	// 	for(int j=0;j<m;j++){
	// 		B.a[j][j]=1;
	// 		B.a[(j-i+m)%m][j]+=1;
	// 	}
	// 	// A=A*B.get(a[i]);
	// }

	cout<<(A.a[0][0]-1+mod)%mod<<'\n';
	// auto sol = [&](long long val) -> void{
	// 	for(int i=0;i<m;i++){
	// 		dpp[(i+val)%m]=dp[i]+dp[(i+val)%m];
	// 		dpp[(i+val)%m]%=mod;
	// 	}
	// 	for(int i=0;i<m;i++){
	// 		dp[i]=dpp[i];
	// 		dpp[i]=0;
	// 	}
	// };
	// for(int i=0;i<m;i++){
	// 	long long x=a[i];
	// 	long long y=1;
	// 	while(x>=y){
	// 		sol(i*y);
	// 		x-=y;
	// 		y<<=1;
	// 	}
	// 	if(x){
	// 		sol(i*x);
	// 	}
	// }
	// cout<<dp[0]-1<<'\n';
	// // for(int i=0;i<m;i++){
	// // 	cout<<a[i]<<" \n"[i==m-1];
	// // }
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}