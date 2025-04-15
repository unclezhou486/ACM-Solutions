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

long long inv(long long x){
	return qmi(x,mod-2);
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> air(n+10);
	vector<int> val(n+10);
	for(int i=1;i<=n;i++){
		val[i]=1ll*(n-i)*inv(1+i)%mod;
	}
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		air[x]=1;
	}
	vector<int> cnt(n+10),vis(n+10),vec,s;
	int len=0;
	for(int i=1;i<=n;i++){
		len++;
		if(air[i]){
			s.push_back(len);
			len=0;
		}
	}
	s.push_back(len+1);
	vector<int> b(n+10),c(n+10);
	for(int i=0;i<s.size();i++){
		for(auto x:vec){
			int resa=x,resb=s[i];
			int appcnt=cnt[x];
			if(resa>resb){
				swap(resa,resb);
			}
			(b[2]+=appcnt)%=mod;
			(b[resa+2]-=appcnt)%=mod;
			(b[resb+2]-=appcnt)%=mod;
			(b[resa+resb+2]+=appcnt)%=mod;
		}
		if(i-1>=0){
			cnt[s[i-1]]+=1;
			if(!vis[s[i-1]]){
				vis[s[i-1]]=1;
				vec.push_back(s[i-1]);
			}
		}
	}
	for(int i=1;i<s.size();i++){
		int resa=s[i-1],resb=s[i]-1;
		if(!resb) continue;
		if(resa>resb){
			swap(resa,resb);
		}
		b[2]+=1;
		b[resa+2]-=1;
		b[resb+2]-=1;
		b[resa+resb+2]+=1;
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<b[i]<<" \n"[i==n];
	// }
	for(int i=0;i<s.size();i++){
		int res=s[i];
		if(i==s.size()-1) res-=1;
		if(!res) continue;
		c[0]-=1;
		c[res]+=1;
	}
	for(int i=n;i>=1;i--){
		c[i]+=c[i+1];
		c[i]%=mod;
	}
	for(int i=n;i>=1;i--){
		c[i]+=c[i+1];
		c[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		b[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		b[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		b[i]=(b[i]+c[i]+mod)%mod;
	}
	// b[1]=n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=(1ll*b[i]*val[i]%mod);
		ans%=mod;
		// cout<<b[i]<<" \n"[i==n];
	}
	cout<<ans<<'\n';
}

// 1 1 2 1 1 2 1 1 2

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