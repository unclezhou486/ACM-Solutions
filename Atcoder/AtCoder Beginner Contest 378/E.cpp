#include <bits/stdc++.h>

using namespace std;

struct BIT{
	int n;
	vector<int> a;
	void init(int _n){
		this->n=_n+10;
		a.assign(n,{});
	}
	void add(int k,int x){
		k+=1;
		for(;k<=n;k+=k&-k){
			a[k]+=x;
		}
	}
	int query(int x){
		int res=0;
		x+=1;
		for(;x;x-=x&-x){
			res+=a[x];
		}
		return res;
	}
	int sum(int l,int r){
		return query(r)-query(l-1);
	}
};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<long long> a(n+10),pre(n+10);
	BIT bit;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=(pre[i-1]+a[i])%m;
	}
	bit.init(m);
	long long ans=0;
	long long res=0;
	for(int i=1;i<=n;i++){
		ans+=1ll*pre[i]*i-res+1ll*m*(bit.sum(pre[i]+1,m));
		res+=pre[i];
		if(i)bit.add(pre[i],1);
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}