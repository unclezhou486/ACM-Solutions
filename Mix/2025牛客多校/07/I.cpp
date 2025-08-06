#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998244353;

constexpr int bit = 15;

struct Mat {
	int n, m;
	vector<vector<int> > a;
	vector<int> & operator [](int i) {return a[i];}
	const vector<int> & operator [](int i) const {return a[i];}
	Mat(int _n, int _m ) : n(_n), m(_m) {
		a.assign(n, vector<int>(m, 0));
	}
	const Mat operator*(const Mat &b) const {
		assert(m == b.n);
		Mat c(n, b.m);
		for (int i = 0; i < n; ++i) {
			for (int k = 0; k < m; ++k) {
				int t = a[i][k];
				for (int j = 0; j < b.m; ++j) {
					c[i][j] += 1LL * t * b[k][j] % MOD;
					c[i][j] %= MOD;
				}
			}
		}
		return c;
	}
	Mat& operator*=(const Mat& b) {
		*this = (*this) * b;
		return *this;
	}
	void print(){
		cout<<"Mat:\n";
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout<<a[i][j]<<" \n"[j==m-1];
			}
		}
	}
};

Mat Matpow(Mat a,long long b){
	Mat res(a.n,a.n);
	for(int i=0;i<a.n;i++){
		res[i][i]=1;
	}
	while(b){
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

long long qpow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

long long rev(long long x){
	return qpow(x,MOD-2);
}


void solve() {
	long long n;
	int k;
	cin>>n>>k;
	vector<int> d(k);
	for(int i=0;i<k;i++){
		cin>>d[i];
	}
	Mat a(1,32);
	Mat b(32,32);
	for(int i=0;i<k;i++){
		a[0][d[i]]=d[i];
		a[0][d[i]+16]=1;
	}
	for(int i=0;i<16;i++){
		for(auto j:d){
			{
				int x=(i|j);
				b[i][x]+=1;
				b[i+16][x]=(b[i+16][x]+(x-i+MOD)%MOD)%MOD;
				b[i+16][x+16]+=1;
			}
			{
				int x=(i&j);
				b[i+16][x]+=x;
				b[i+16][x+16]+=1;

			}
			{
				int x=(i^j);
				b[i][x]+=1;
				b[i+16][x]=(b[i+16][x]+(x-i+MOD)%MOD)%MOD;
				b[i+16][x+16]+=1;

			}
			{
				int x=(i+j)&bit;
				b[i][x]+=1;
				b[i+16][x]+=j;
				b[i+16][x+16]+=1;

			}
			{
				int x=(i*j)&bit;
				b[i][x]+=j;
				b[i+16][x+16]+=1;
			}
		}
	}
	b=Matpow(b,n-1);
	a=a*b;
	long long ans=0;
	long long cnt=0;
	for(int i=0;i<16;i++){
		ans+=a[0][i];ans%=MOD;
		cnt+=a[0][i+16];cnt%=MOD;
	}
	cout<<ans*rev(cnt)%MOD<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}