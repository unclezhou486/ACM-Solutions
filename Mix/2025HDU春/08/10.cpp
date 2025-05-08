#include <bits/stdc++.h>

using namespace std;

constexpr int mod=10007;


void solve(){
	int k;
	int c,d,e,f;
	cin>>k>>c>>d>>e>>f;
	int ans=0;
	auto check = [&](int y,long long x) -> bool{
		vector<int> a(20);
		int id=0;
		bool flag=true;
		while(x){
			a[id]=x%27;
			x/=27;
			if(!a[id]) flag=false;
			id++;
		}
		if(flag&&id&&id<=k){
			long long res=0;
			int mi=1;
			for(int i=0;i<id;i++){
				res+=a[i]*mi;
				res%=mod;
				mi=(mi*10)%mod;
			}
			if(res==y) return true;
		}
		return false;

	};
	for(int i=0;i<=10006;i++){
		long long res=1ll*i*i*i*c+1ll*i*i*d+1ll*i*e+f;
		if(check(i,res)) ans+=1;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}