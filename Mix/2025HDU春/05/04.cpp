#include<bits/stdc++.h>
using namespace std;

constexpr int mod=998244353;

struct node{
	vector<int> a;
	// vector<int> b;
	int n;
	node():n(0){}
	node(int x) : a(vector<int>(x)),n(x) {}
	node operator*(const node &b) const{
		// vector<int> c(n+10,0);
		node c(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				(c.a[(i+j)%n]+=(1ll*a[i]*b.a[j])%mod)%=mod;
			}
		}
		return c;
	}
};

node qmi(node a,long long b){
	node res(a.n);
	res.a[0]=1;
	while(b){
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

void solve(){
	long long n;
	int m;
	cin>>n>>m;
	vector<int> a(m);
	long long res=n/m;
	node ans(m);
	ans.a[0]=1;
	node ress(m);
    ress.a[0]=1;
	for(int i=0;i<m;i++){
		node b(m);
		b.a[0]=1;
		b.a[i]+=1;
		ress=ress*b;
	}
	ans=ans*qmi(ress,res);
	for(int i=1;i<=n-res*m;i++){
		node b(m);
		b.a[0]=1;
		b.a[i]+=1;
		ans=ans*b;
	}
	cout<<(ans.a[0]-1+mod)%mod<<'\n';
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
