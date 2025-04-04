#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> p(n+10),d(n+10),vis(n+10);
	vector<int> f(n+10),len(n+10);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>d[i];
		f[i]=i;
	}
	auto find = [&](auto self,int x,int fa) -> int {
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int x=i;
			int cnt=1;
			x=p[x];
			f[x]=i;
			while(x!=i){
				vis[x]=1;
				cnt+=1;
				f[x]=i;
				x=p[x];
			}
			len[i]=cnt;
		}
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<f[i]<<" \n"[i==n];
	// }
	// for(int i=1;i<=n;i++){
	// 	cout<<len[i]<<" \n"[i==n];
	// }
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=len[f[d[i]]];
		len[f[d[i]]]=0;
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
