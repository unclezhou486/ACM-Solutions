#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int u,v,w;
};

void solve(){
	int n,m,q,v;
	cin>>n>>m>>q>>v;
	vector<node> a(m+10);
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	vector<int> b;
	int idi;
	for(idi=60;idi>0;idi--){
		if((v>>idi)&1){
			break;
		}
		b.push_back((1ll<<idi));
	}
	int res=0;
	for(idi;idi>=0;idi--){
		if((v>>idi)&1){
			res|=(1ll<<idi);
		}
		else{
			b.push_back((v&res)|(1ll<<idi));
		}
	}
	b.push_back(v);
	vector<int> f(n+10);
	vector<vector<int> > ans(64,vector<int>(n+10));  
	auto find = [&](auto self,int x) -> int {
		return x==f[x]?x:f[x]=self(self,f[x]);
	};
	int cnt=0;
	for(auto x:b){
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++){
			if((a[i].w&x)==x){
				f[find(find,a[i].u)]=find(find,a[i].v);
			}
		}
		for(int i=1;i<=n;i++){
			ans[cnt][i]=find(find,i);
		}
		cnt+=1;
	}
	// int q;
	// cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		bool flag=false;
		for(int i=0;i<b.size();i++){
			if(ans[i][u]==ans[i][v]) flag=true;
		}
		if(flag){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}