#include <bits/stdc++.h>
#define int long long
using namespace std;

struct BIT{
	vector<int> bit;
	int n;
	void init(int n){
		n+=10;
		this->n=n;
		bit.assign(n,{});
	}
	int lowbit(int x){
		return x&-x;
	}
	void add(int k,int x){
		for(;k<=n;k+=lowbit(k)){
			bit[k]+=x;
		}
	}
	int query(int x){
		int res=0;
		for(;x;x-=lowbit(x)){
			res+=bit[x];
		}
		return res;
	}
}bit;

void solve(){
	int n,q;
	cin>>n>>q;
	bit.init(n);
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bit.add(i,a[i]);
	}	
	long long cnt=0;
	long long ans=0;
	for(int i=1;i<=q;i++){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			bit.add(x,-a[x]);
			a[x]=y;
			bit.add(x,a[x]);
		}
		else{
			long long res;
			res=bit.query(y)/100-bit.query(x-1)/100;
			cnt++;
			// cout<<res<<'\n';
			ans^=(cnt*res);
		}
	}
	cout<<ans<<'\n';
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