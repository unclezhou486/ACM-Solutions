#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > adj(3*n+10);
	map<pair<int,int>,int>ma;
	vector<int> ru(3*n+10);
	vector<tuple<int,int,int> > vec(m+10);
	for(int i=1;i<=m;i++){
		auto &[x,y,z]=vec[i];
		cin>>x>>y>>z;
	}
	for(int i=1;i<=m;i++){
		// int x,y,c;
		auto [x,y,c]=vec[i];
		// cin>>x>>y>>c;
		int x1=(y+1)/2;
		int x2=(2*n-x+1);
		int x3=(2*x-1-y+1+1)/2+2*n;
		// cout<<x1<<' '<<x2<<' '<<x3<<'\n';
		if(ma.count({x,y})){
			if(ma[{x,y}]!=c){
				cout<<"No\n";
				return;
			}
			else{
				continue;
			}
		}
		ma[{x,y}]=c;
		if(c==x1){
			;
		}
		else if(c==x2){
			swap(x2,x1);
		}
		else if(c==x3){
			swap(x3,x1);
		}
		else{
			cout<<"No\n";
			return;
		}
		adj[x1].push_back(x2),adj[x1].push_back(x3);
		ru[x2]+=1;
		ru[x3]+=1;
	}	
	queue<int> q;
	for(int i=1;i<=3*n;i++){
		if(!ru[i]){
			q.push(i);
		}
	}
	while(q.size()){
		int x=q.front();
		q.pop();
		for(auto y:adj[x]){
			ru[y]--;
			if(ru[y]==0){
				q.push(y);
			}
		}
	}
	bool flag=true;
	for(int i=1;i<=3*n;i++){
		if(ru[i]) flag=false;
	}
	if(flag){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
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

/*

1
2 4
2 2 5
2 1 1
2 3 2
1 1 5

*/