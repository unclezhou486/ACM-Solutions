#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e6+10;

int f[N<<1];
int bian[N<<1];
int id[N<<1];

int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) f[i]=i+n;
	for(int i=n+1;i<=2*n;i++) f[i]=i,bian[i]=i-n,id[i]=i;
	for(int i=1;i<=q;i++){
		int op,a,b;
		cin>>op;
		if(op==1){
			cin>>a>>b;
			a+=n,b+=n;
			f[find(id[b])]=find(id[a]);
		}
		else if(op==2){
			cin>>a>>b;
			b+=n;
			f[a]=find(id[b]);
		}
		else if(op==3){
			cin>>a>>b;
			a+=n;
			b+=n;
			swap(bian[id[a]],bian[id[b]]);
			swap(id[a],id[b]);
		}
		else if(op==4){
			cin>>a;
			cout<<bian[find(a)]<<'\n';
		}
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