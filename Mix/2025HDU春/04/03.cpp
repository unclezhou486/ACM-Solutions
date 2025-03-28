#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	long long k,b,c,v;	
	cin>>k>>b>>c>>v;
	long long res=0;
	vector<int> bitc(70),bitv(70);
	for(int i=0;i<=60;i++){
		bitc[i]=(c>>i)&1;
		bitv[i]=(v>>i)&1;
	}
	long long ans=0;
	if(((v^c)-b)%k==0&&(v^c)-b>=0) ans=1;
	auto check = [&](long long y) -> long long {
		if(y<b) return 0;
		// if(y==b) return 1;
		return (y-b)/k+1;
	};
	for(int i=60;i>=0;i--){
		if(bitv[i]==1){
			long long ress=bitc[i];
			long long resx=res|(ress<<i);
			long long l=resx,r=resx+(1ll<<i)-1;
			// l=l,r=r;
			ans+=check(r)-check(l-1);
			res|=(ress^1)<<i;
		}
		else{
			res|=(bitc[i])<<i;
		}
	}
	cout<<ans<<'\n';
}

//1 0 1
//0 1 1
//0 0 0
//1 1 0


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