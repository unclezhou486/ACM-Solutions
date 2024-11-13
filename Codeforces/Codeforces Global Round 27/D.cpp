#include <bits/stdc++.h>

using namespace std;

constexpr int MOD=1e9+7;

long long qmi(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

bool cmp(long long x,long long a,long long b){
	if(b<=63){
		__int128 d=2;
		__int128 y=pow(2,b);
		y=y*a;
		if(x<=y) return 1;
		else return 0;
	}
	else{
		return 1;
	}
}

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n+10),b(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]%2==0){
			a[i]/=2;
			b[i]++;
		}
	}
	stack<pair<long long,int> > st;
	long long ans=0;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&cmp(st.top().first,a[i],b[i])){
			b[i]+=st.top().second;
			ans=(ans-1ll*st.top().first*((qmi(2,st.top().second)-1+MOD)%MOD)%MOD+MOD)%MOD;
			st.pop();
		}
		if(b[i])st.push({a[i],b[i]});
		// cout<<a[i]<<' '<<b[i]<<'\n';
		ans=(ans+1ll*a[i]*qmi(2,b[i]))%MOD;
		cout<<ans<<" \n"[i==n];
	}
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