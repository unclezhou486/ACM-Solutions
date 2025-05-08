#include<bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

long long qmi(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

void solve(){
	int n,m,v;
	cin>>n>>m>>v;
	map<int,int> ma;
	bool flag=true;
	for(int i=1;i<=m;i++){
		int c,d;
		cin>>c>>d;
		if(ma.count(c)&&ma[c]!=d){
			flag=false;
		}
		ma[c]=d;
	}
	if(!flag){
		cout<<0<<'\n';
		return;
	}
	int cnt=n-1;
	long long ans=qmi(v,2*cnt);
	int la=0;
	for(auto [c,d]:ma){
		if(la!=0){
			ans-=qmi(v,c-la-1)*(v-1)%mod;
			ans=(ans%mod+mod)%mod;
		}
		la=c;
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("assign3.in","r",stdin);
	freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


/*

-(v-1)*(v^(next-last-1))

1 0 0 0 2
1 2 3 4 
2 3 4 2

1 2
1 
2

*/

