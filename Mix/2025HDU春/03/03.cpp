#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int val,id;
	bool operator<(const node &a) const{
		return val<a.val;
	}
};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > c(n+10,vector<int>(m+10)),w(n+10,vector<int>(m+10));
	vector<int> a(m+10);
	vector<int> b(n+10,m);
	vector<int> idd(m+10,1);
	vector<vector<node> > cc(m+10,vector<node>(n+10) );
	vector<int> vis(n+10);
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			cc[j][i]=(node){c[i][j],i};
		}
		for(int j=1;j<=m;j++){
			cin>>w[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		sort(cc[i].begin()+1,cc[i].begin()+1+n);
	}
	bool flag=true;
	while(flag){
		flag=false;
		queue<int> qu;
		for(int i=1;i<=m;i++){
			while(idd[i]<=n&&cc[i][idd[i]].val<=a[i]){
				b[cc[i][idd[i]].id]-=1;
				if(b[cc[i][idd[i]].id]==0){
					flag=true;
					vis[cc[i][idd[i]].id]=1;
					qu.push(cc[i][idd[i]].id);
				}
				idd[i]+=1;
			}
		}
		while(qu.size()){
			int x=qu.front();
			qu.pop();
			for(int j=1;j<=m;j++){
				a[j]+=w[x][j];
			}
		}
	}
	bool ans=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]) ans=false;
	}
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}