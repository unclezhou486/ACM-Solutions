#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod=998244353;

long long qmi(long long a,long long b){
	a%=mod;
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

long long inv(long long x){
	return qmi(x,mod-2);
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> p(k+10);
	// map<map<int,int>> ma;
	// map<pair<int,int>,int> ma;
	map<int,int> ma;
	vector<pair<int,int> > id;
	// id.push_back({0,0});
	set<int> se;
	int inv2=inv(2);
	for(int i=0;i<=k;i++){
		cin>>p[i];
		p[i]--;
		if(i>0) ma[{p[i],p[i]}]=1;
		se.insert(p[i]);
	}
	ma[{p[0],p[0]}]=0;
	int ansl=p[0],ansr=p[0];
	for(int i=0;i<=30;i++){
		set<pair<int,int> > app;
		for(auto x:se){
			int l,r;
			int L,R;
			l=L=(x>>i)<<i;
			int len;
			if(!i) len=0;
			else len=(1<<(i))-1;
			if((x>>i)&1){
				r=l+len;
				L=L-(1<<i);
				R=L+len;
			}
			else{
				r=l+len;
				L=L+(1<<i);
				R=L+len;
			}
			if(l>L) swap(l,L),swap(r,R);
			if(app.count({l,R})) continue;
			app.insert({l,R});
			int p1=ma[{l,r}],p2=ma[{L,R}];
			if((l<=p[0]&&p[0]<=r)||(L<=p[0]&&p[0]<=R)){
				ma[{l,R}]=(p1+1ll*(1-p1+mod)*(p2)%mod)%mod;
			}
			else{
				ma[{l,R}]=(1ll*(p1)*(p2)%mod + 1ll*inv2*((1ll*(1-p1+mod)%mod)*p2%mod + 1ll*(p1)*(1-p2+mod)%mod ))%mod;
			}
		}
		se.clear();
		for(auto [a,b]:app){
			se.insert(a);
			ansl=a,ansr=b;
		}
	}

	cout<<(1-ma[{ansl,ansr}]+mod)%mod<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// cout<<(1<<30)<<'\n';
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}