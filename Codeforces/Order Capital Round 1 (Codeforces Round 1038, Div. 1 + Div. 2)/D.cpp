#include <bits/stdc++.h>

using namespace std;

struct node{
	int res1,res2;
	bool operator<(const node &a) const{
		if(res1==a.res1) return res2<a.res2;
		return res1<a.res1;
	}
	bool operator>(const node &a) const{
		if(res1==a.res1) return res2>a.res2;
		return res1>a.res1;
	}
	node min(const node &a,const node &b) const{
		if(a<b) return a;
		return b;
	}
	node operator+(int x)const{
		return (node){res1+x,res2+x};
	}
};

bool flag=false;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> >adj(n+10);
	vector<pair<int,int> > vec;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		// vec.push_back({u,v});
		// if(flag==true){
		// 	cout<<u<<' '<<v<<'\n';
		// }
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	priority_queue<pair<node,int> ,vector<pair<node,int> > ,greater<> > q;
	vector<vector<node> > d(n+1,vector<node>(n+1,(node){1000000000,1000000000}));
	d[1][0]={0,0};
	q.push({d[1][0],1});
	vector<set<int> > vis(n+1);
	while(q.size()){
		auto [dis,x]=q.top();
		auto [dis1,dis2]=dis;
		q.pop();
		int siz=adj[x].size();
		int time=dis1%siz;
		if(vis[x].count(dis1)) continue;
		vis[x].insert(dis1);
		for(int i=0;i<n;i++){
			node res=dis;
			res=res+i;
			int j=(res.res1)%siz;
			if(j>3*n) break;
			if(res<d[x][j]){
				d[x][j]=res;
				q.push({d[x][j],x});
			}
			node ress=res;
			ress.res1+=1;
			int y=adj[x][j];
			int timey=(ress.res1)%((int)adj[y].size());
			if(ress.res1>3*n) continue;
			if(ress<d[y][timey]){
				// vis[y][timey]=0;
				d[y][timey]=ress;
				q.push({d[y][timey],y});
			}
		}
	}
	node ans={1000000000,1000000000};
	for(int i=0;i<n;i++){
		if(d[n][i]<ans){
			ans=d[n][i];
		}
	}
	cout<<ans.res1<<' '<<ans.res2<<'\n';
	// if(ans.res1==8&&ans.res2==3){
	// 	cout<<n<<' '<<m<<'\n';
	// 	cout<<"ID:\n";
	// 	for(auto [u,v]:vec){
	// 		cout<<u<<' '<<v<<'\n';
	// 	}
	// }
}

//0 1 2 3

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