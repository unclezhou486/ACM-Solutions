#include <bits/stdc++.h>

using namespace std;

constexpr int N=2e6+10;

struct node{
	int u,v;
}arr[N];
bool vis[N];
int f[N];
int cnt[N];

struct que{
	int op,u,v;
}qu[N];

map<pair<int,int>,int> ma;

int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int u=(a-1)*m+b;
		int v=(c-1)*m+d;
		if(u>v) swap(u,v);
		arr[i]={u,v};
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			int u=(a-1)*m+b;
			int v=(c-1)*m+d;
			if(u>v) swap(u,v);
			ma[{u,v}]=1;
			qu[i]={1,u,v};
		}
		else{
			int x,y;
			cin>>x>>y;
			qu[i]={2,x,y};
		}
	}
	for(int i=1;i<=k;i++){
		if(ma.count({arr[i].u,arr[i].v})){
			vis[i]=1;
		}
	}
	for(int i=1;i<=n*m;i++){
		f[i]=i;
		cnt[i]=1;
	}
	for(int i=1;i<=k;i++){
		if(vis[i]) continue;
		auto [u,v]=arr[i];
		if(find(u)!=find(v)){
			cnt[find(u)]+=cnt[find(v)];
			f[find(v)]=find(u);
		}
	}
	vector<int> ans;
	for(int i=q;i>=1;i--){
		if(qu[i].op==2){
			auto [op,x,y]=qu[i];
			ans.push_back(cnt[find((x-1)*m+y)]);
			// cout<<cnt[find((x-1)*m+y)]<<'\n';
		}
		else{
			auto [op,u,v]=qu[i];
			if(find(u)!=find(v)){
				cnt[find(u)]+=cnt[find(v)];
				f[find(v)]=find(u);
			}
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans){
		cout<<x<<'\n';
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