#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int G = 3;  // 原根


struct Poly {
    vector<int> a;
    Poly() {}
    Poly(const vector<int>& _a) : a(_a) {}
	int& operator[](int i) { return a[i]; }
	const int& operator[](int i) const { return a[i]; }
	int power(int a, int b) {
	    int res = 1;
	    while (b) {
	        if (b & 1) res = (int)(1LL * res * a % MOD);
	        a = (int)(1LL * a * a % MOD);
	        b >>= 1;
	    }
	    return res;
	}
    static int revbit(int x, int bitlen) {
        int res = 0;
        for (int i = 0; i < bitlen; i++) {
            if (x & (1 << i)) res |= (1 << (bitlen - 1 - i));
        }
        return res;
    }
    void ntt(int invert) {
        int n = (int)a.size();
        int bitlen = 0;
        while ((1 << bitlen) < n) bitlen++;
        for (int i = 0; i < n; i++) {
            int j = revbit(i, bitlen);
            if (i < j) swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            int wlen = power(G, (MOD - 1) / len);
            if (invert == -1) wlen = power(wlen, MOD - 2);
            for (int i = 0; i < n; i += len) {
                int w = 1;
                for (int j = 0; j < len / 2; j++) {
                    int u = a[i + j];
                    int v = (int)(1LL * a[i + j + len / 2] * w % MOD);
                    a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                    a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                    w = (int)(1LL * w * wlen % MOD);
                }
            }
        }
        if (invert == -1) {
            int inv_n = power(n, MOD - 2);
            for (int &x : a) x = (int)(1LL * x * inv_n % MOD);
        }
    }
    Poly operator*(const Poly &b) const {
        vector<int> fa(a.begin(), a.end()), fb(b.a.begin(), b.a.end());
        int n = 1;
        while (n < (int)(fa.size() + fb.size() - 1)) n <<= 1;
        fa.resize(n);
        fb.resize(n);

        Poly A(fa), B(fb);
        A.ntt(1);
        B.ntt(1);
        for (int i = 0; i < n; i++) {
            A.a[i] = (int)(1LL * A.a[i] * B.a[i] % MOD);
        }
        A.ntt(-1);
        A.a.resize(a.size() + b.a.size() - 1);
        return A;
    }
    Poly operator+(const Poly &b) const {
        int n = (int)max(a.size(), b.a.size());
        vector<int> res(n, 0);
        for (int i = 0; i < (int)a.size(); i++) {
            res[i] = a[i];
        }
        for (int i = 0; i < (int)b.a.size(); i++) {
            res[i] += b.a[i];
            if (res[i] >= MOD) res[i] -= MOD;
        }
        return Poly(res);
    }
};

int qpow(int a,int b){
	int res=1;
	a%=MOD;
	while(b){
		if(b&1) res=1ll*res*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return res;
}

int inv(int x){
	return qpow(x,MOD-2);
}

constexpr int N=2e5+10;

int mi[N],iv[N];

void init(){
	mi[0]=1;
	for(int i=1;i<=N-10;i++){
		mi[i]=1ll*mi[i-1]*i%MOD;
	}
	iv[N-10]=inv(mi[N-10]);
	for(int i=N-10;i>=1;i--){
		iv[i-1]=1ll*iv[i]*i%MOD;
	}
}

int C(int n,int m){
	if(n<m||m<0) return 0;
	return 1ll*mi[n]*iv[m]%MOD*iv[n-m]%MOD;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1),vis(n+1);
	vector<int> b;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=-1){
			vis[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cnt++;
			b.push_back(i);
		}
	}
	int inv2=inv(2);
	auto sol = [&](auto &&sol,int l,int r) -> pair<Poly,Poly> {
		if(l>r){
			return {Poly({1}),Poly({1})};
		}
		if(l==r){
			int x=b[l];
			Poly a({1,(int)((1ll*x+inv(x))%MOD*inv2%MOD)});
			Poly b({0,x});
			return {a,b};
		}
		int mid=(l+r)>>1;
		auto [al,ar] = sol(sol,l,mid);
		auto [bl,br] = sol(sol,mid+1,r);
		return {al*bl,(al*br)+(ar*bl)};
	};
	auto [A,B]=sol(sol,0,cnt-1);
	int ans=0;
	int res=1;
	int cntt=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			if(i!=1)res=1ll*res*(1ll*(a[i]+inv(a[i]))%MOD)%MOD*inv2%MOD;
			else res=1ll*res*a[i]%MOD;
		}
		else{
			cntt++;
		}
		if(i!=n) res=1ll*res*inv2%MOD;//minus + -
		if(a[1]==-1){
			ans=ans+1ll*res*B[cntt]%MOD*inv(C(cnt-1,cntt-1))%MOD*inv(cnt)%MOD;
			ans%=MOD;
		}
		else{
			// cout<<A[cntt]<<' '<<C(cnt,cntt)<<'\n';
			// cout<<1ll*res*A[cntt]%MOD*inv(C(cnt,cntt))%MOD<<'\n';
			ans=ans+1ll*res*A[cntt]%MOD*inv(C(cnt,cntt))%MOD;
			ans%=MOD;
		}
		// cout<<res<<'\n';
	}
	cout<<ans<<'\n';
}



int main(){
	// int res=1;
	// res=res*1ll*5*inv(4)%MOD;
	// cout<<res<<'\n';
	// res=res*1ll*5*inv(3)%MOD;
	// cout<<res<<'\n';
	// res=res*1ll*17*inv(8)%MOD;
	// cout<<res<<'\n';
	// res=res*1ll*13*inv(5)%MOD;
	// cout<<res<<'\n';
	init();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}