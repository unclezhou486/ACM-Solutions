// #pragma GCC O(2)
// #pragma GCC O(3)

#include <bits/stdc++.h>

using namespace std;

int mi[20];

void solve(){
	int n,m,k,p;
	cin>>n>>m>>k>>p;
	vector<vector<pair<int,int> > > adj(n+10);
	vector<int> ss(k+10),tt(k+10);
	vector<int> id(n+10);
	for(int i=1;i<=m;i++){
		int u,v,t;
		cin>>u>>v>>t;
		adj[u].push_back({v,t});
		adj[v].push_back({u,t});
	}
	vector<int> vec;
	vector<int> viss(n+10);
	if(!viss[p]){
		viss[p]=1;
		vec.push_back(p);
	}
	for(int i=1;i<=k;i++){
		cin>>ss[i]>>tt[i];
		if(!viss[ss[i]]){
			viss[ss[i]]=1;
			vec.push_back(ss[i]);
		}
		if(!viss[tt[i]]){
			viss[tt[i]]=1;
			vec.push_back(tt[i]);
		}
	}
	// map<pair<int,int>,long long> dis;
	vector<map<int,long long > > dis(n+10);
	auto dij = [&] (int s) -> void {
		vector<int> vis(n+10);
		vector<long long> d(n+10,1e18);
		d[s]=0;
		priority_queue<pair<long long,int>,vector<pair<long long,int> > ,greater<> > q;
		q.push({d[s],s});
		while(q.size()){
			auto [distance,x]=q.top();
			q.pop();
			if(vis[x]) continue;
			vis[x]=1;
			for(auto [y,w]:adj[x]){
				if(d[y]>d[x]+w){
					d[y]=d[x]+w;
					q.push({d[y],y});
				}
			}
		}
		// for(int i=1;i<=n;i++){
		// 	// dis[{s,i}]=d[i];
		// 	dis[s][i]=d[i];
		// }
		for(int i=1;i<=k;i++){
			dis[s][ss[i]]=d[ss[i]];
			dis[s][tt[i]]=d[tt[i]];
		}
		dis[s][p]=d[p];
	};
	// return;
	int cnt=0;
	for(auto x:vec){
		id[x]=cnt++;
		dij(x);
		// return;
	}
	// return ;
	int nn=vec.size();
	vector<vector<pair<int,long long> > > adjj(nn+10);
	for(int i=0;i<nn;i++){
		for(int j=0;j<nn;j++){
			adjj[i].push_back({j,dis[vec[i]][vec[j]]});
		}
	}
	// vector<vector<long long> > (nn+10,vector<long long>(60000,2e18));
	// auto dijj= [&](int s) -> void{
	vector<vector<int> > vis(nn+10,vector<int>(mi[k]+10));
	vector<vector<long long> > d(nn+10,vector<long long>(mi[k]+10,2e18));
	priority_queue<pair<long long,pair<int,int> > ,vector<pair<long long,pair<int,int> > > ,greater<>> q;
	auto change= [&](int statu,int x) -> int {
		int statuu=statu;
		for(int i=0;i<k;i++){
			if(statu%3==0&&id[ss[i+1]]==x){
				statuu+=mi[i];
			}
			else if(statu%3==1&&id[tt[i+1]]==x){
				statuu+=mi[i];
			}
			statu/=3;
		}
		return statuu;
	};
	int stau=change(0,0);
	d[0][stau]=0;
	// vis[0][0]=1;
	q.push({d[0][stau],{stau,0}});//dis sta pos
	while(q.size()){
		auto [distance,pos]=q.top();
		q.pop();
		auto [sta,x]=pos;
		if(vis[x][sta]) continue;
		vis[x][sta]=1;
		if(sta==mi[k]-1) break;
		for(auto [y,w]:adjj[x]){
			int staa=change(sta,y);
			if(d[y][staa]>d[x][sta]+w){
				d[y][staa]=d[x][sta]+w;
				q.push({d[y][staa],{staa,y}});
			}
		}
	}
	long long ans=4e18;
	int res=mi[k]-1;
	for(int i=0;i<nn;i++){
		ans=min(ans,d[i][res]);
	}
	cout<<ans<<'\n';
	// };
}

int main(){
	// freopen("1.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	mi[0]=1;
	for(int i=1;i<=10;i++){
		mi[i]=mi[i-1]*3;
	}
	while(t--){
		solve();
	}
	return 0;
}

/*

20 19 10 1
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
7 8 1
8 9 1
9 10 1
10 11 1
11 12 1
12 13 1
13 14 1
14 15 1
15 16 1
16 17 1
17 18 1
18 19 1
19 20 1
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
17 18
19 20



*/