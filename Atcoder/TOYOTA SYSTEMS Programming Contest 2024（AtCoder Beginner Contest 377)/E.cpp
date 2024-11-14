#include <bits/stdc++.h>

using namespace std;

long long qmi(long long a,long long b,long long mod){
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
	long long k;
	cin>>n>>k;
	vector<int> p(n+1);
	vector<int> len(n+1);
	vector<int> vis(n+1);
	vector<vector<int> > qu(n+1);
	vector<int> ans(n+1);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	auto dfs=[&](auto self,int x) -> void {
		int y=p[x];
		if(len[y]) return;
		else{
			len[y]=len[x]+1;
			self(self,y);
			len[x]=len[y];
		}
	};
	auto cheng=[&](vector<int> &a,vector<int> &b) -> vector<int> {
		vector<int> c(n+1);
		for(int i=1;i<=n;i++){
			c[i]=a[b[i]];
		}
		return c;
	};
	auto vpow = [&] (vector<int> a,long long b) -> vector<int> {
		vector<int> res(n+1);
		for(int i=1;i<=n;i++) res[i]=i;
		while(b){
			if(b&1) res=cheng(res,a);
			a=cheng(a,a);
			b>>=1;
		}
		return res;
	};
	for(int i=1;i<=n;i++){
		if(!len[i]){
			len[i]=1;
			dfs(dfs,i);
		}
	}
	for(int i=1;i<=n;i++){
		qu[len[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!ans[i]){
			vector<int> a=p;
			vector<int> aa=vpow(a,qmi(2,k,len[i]));
			for(auto x:qu[len[i]]){
				ans[x]=aa[x];
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
	}
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