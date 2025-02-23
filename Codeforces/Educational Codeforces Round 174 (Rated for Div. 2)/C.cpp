#include <bits/stdc++.h>

using namespace std;

constexpr int mod=998244353;

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
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	long long ans=0;
	long long res=0;
	int cnt2=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=2){
			res*=qmi(2,cnt2);
			res%=mod;
			cnt2=0;
			if(a[i]==1){
				res+=1,cnt+=1;
			}
			else{
				ans+=res-cnt;
				ans%=mod;
				ans+=mod;
				ans%=mod;
			}
		}
		else if(a[i]==2){
			cnt2++;
		}
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