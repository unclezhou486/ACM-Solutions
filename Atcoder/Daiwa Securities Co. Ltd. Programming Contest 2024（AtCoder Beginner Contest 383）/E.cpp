#include <bits/stdc++.h>

using namespace std;

struct node{
	int u,v,w;
	bool operator< (const node &a) const{
		return w<a.w;
	}
};

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<node> line(m);
	vector<int> a(k+10),b(k+10);
	vector<int> cnta(n+10),cntb(n+10);
	vector<int> f(n+10);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		line[i]={u,v,w};
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	auto find = [&] (auto self,int x) -> int {
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	sort(line.begin(),line.end());
	for(int i=1;i<=k;i++){
		cin>>a[i];
		cnta[a[i]]+=1;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		cntb[b[i]]+=1;
	}
	int idx=n;
	long long ans=0;
	for(int i=0;i<m;i++){
		auto [u,v,w]=line[i];
		if(find(find,u)!=find(find,v)){
			idx++;
			int uu=find(find,u);
			int vv=find(find,v);
			cnta[vv]+=cnta[uu];
			cntb[vv]+=cntb[uu];
			f[uu]=vv;
			int res=min(cnta[vv],cntb[vv]);
			ans+=1ll*res*w;
			cnta[vv]-=res;
			cntb[vv]-=res;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}