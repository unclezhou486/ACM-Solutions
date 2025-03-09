#include <bits/stdc++.h>
// #define int long long
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

struct node{
	int ls,rs;
	int l,r;
};

void solve(){
	int n,k;
	cin>>n>>k;
	set<int> se;
	vector<int> p(n+10);
	vector<int> fa;
	vector<node> vec;
	vector<vector<int> > dep(31);
	// int idx=0;
	for(int i=0;i<=k;i++){
		cin>>p[i];
		se.insert(p[i]);
	}
	vec.push_back((node){0,0,1,1<<30});
	dep[0].push_back(vec.size());
	fa.push_back(0);
	for(int i=0;i<30;i++){
		for(auto x:dep[i]){
			auto [ls,rs,l,r]=vec[x-1];
			int mid=l+(r-l+1)/2-1;
			if(*se.lower_bound(l)<=mid){
				vec.push_back((node){0,0,l,mid});
				fa.push_back(x);
				dep[i+1].push_back(vec.size());
			}
			if(*se.lower_bound(mid+1)<=r){
				vec.push_back((node){0,0,mid+1,r});
				fa.push_back(x);
				dep[i+1].push_back(vec.size());
			}
		}
	}
	for(int i=29;i>=0;i--){
		for(auto x:dep[i]){
			auto [ls,rs,l,r]=vec[x-1];
		}
	}
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