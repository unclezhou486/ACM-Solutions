#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<tuple<int,int,int> > a(m+10);
	vector<int> b(m+10),f(n+10);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i]={u,v,w};
	}
	auto find = [&](auto self,int x) -> int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	int ans=0;	
	for(int i=30;i>=0;i--){
		for(int j=1;j<=n;j++){
			f[j]=j;
		}
		for(int j=1;j<=m;j++){
			if(b[j]) continue;
			auto [u,v,w]=a[j];
			if((w>>i)&1) continue;
			int uu=find(find,u),vv=find(find,v);
			if(uu!=vv){
				f[uu]=vv;
			}
		}
		if(find(find,1)!=find(find,n)){
			// cout<<(1<<i)<<'\n';
			ans=ans|(1<<i);
		}
		else{
			for(int j=1;j<=m;j++){
				if(b[j]) continue;
				if((get<2>(a[j])>>i)&1) b[j]=1;
			}
		}
	}
	cout<<ans<<'\n';
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