#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e5+10;

int n,m;
int a[N],b[N];

vector<int> son[N<<1];
int f[N];
int deg[N];
int siz[N];
vector<int> huan[N];
bool vis[N];
int ans[N];

int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		son[a[i]].push_back(i);
		son[b[i]].push_back(i);
	}
	int res=0;
	for(int i=1;i<=m;i++){
		if(son[i].size()==2){
			deg[son[i][0]]+=1;
			deg[son[i][1]]+=1;
			f[find(son[i][0])]=find(son[i][1]);
			res+=1;
		}
	}
	set<int> se;
	for(int i=1;i<=n;i++){
		siz[find(i)]+=1;
		huan[find(i)].push_back(i);
		if(deg[i]==1){
			vis[find(i)]=1;
		}
		se.insert(find(i));
	}
	// set<int> ;
	multiset<int> slian,shuan;
	for(auto x:se){
		if(vis[x]){//lian
			slian.insert(siz[x]);
		}
		else{//huan
			shuan.insert(siz[x]);
		}
	}
	ans[n]=res;
	for(int i=n-1;i>=1;i--){
		if(slian.size()){
			auto it=*slian.begin();
			slian.extract(it);
			it-=1;
			if(it!=0)res-=1,slian.insert(it);
		}
		else if(shuan.size()){
			auto it=*shuan.begin();
			shuan.extract(it);
			res-=2;
			it-=1;
			if(it!=1) slian.insert(it);
		}
		else{
			break;
		}
		ans[i]=res;
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