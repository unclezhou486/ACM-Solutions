#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	vector<int> vis(n+10);
	set<pair<int,int> > se;
	for(int i=1;i<=q;i++){
		int op,x,y;
		cin>>op;
		if(op==1){
			cin>>x>>y;
			se.insert({x,y});
		}
		else if(op==2){
			cin>>x;
			vis[x]=1;
		}
		else{
			cin>>x>>y;
			if(vis[x]||se.count({x,y})){
				cout<<"Yes\n";
			}
			else{
				cout<<"No\n";
			}
		}
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
