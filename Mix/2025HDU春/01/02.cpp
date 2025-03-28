#include<bits/stdc++.h>

using namespace std;

constexpr int mod=998244353;

int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}

int inv(int x){
	return qmi(x,mod-2);
}

void solve(){
	int n,k;
	cin>>n>>k;
	int win;
	cin>>win;
	win--;
	vector<int> p,f;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		x--;
		p.push_back(x);
		f.push_back(1);
	}
	sort(p.begin(),p.end());
	int ans=1;
	int inv2=inv(2);
	while(!p.empty()){
		vector<int> q,g;
		win>>=1;
		for(int i=0;i<p.size();i++){
			if(win==(p[i]>>1)){
				ans=1ll*ans*(1-f[i]+mod)%mod;
			}
			else{
				q.push_back(p[i]>>1);
				if(i<p.size()-1&&(p[i]>>1)==(p[i+1]>>1)){
					g.push_back(1ll*inv2*(f[i]+f[i+1])%mod);
					i+=1;
				}
				else if((p[i]^1)<n){
					g.push_back(1ll*inv2*f[i]%mod);
				}
				else{
					g.push_back(f[i]);
				}
			}
		}
		p=q;
		f=g;
		n=(n+1)>>1;
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
