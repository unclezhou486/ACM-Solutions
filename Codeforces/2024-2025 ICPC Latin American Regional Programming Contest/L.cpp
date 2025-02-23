#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,t;
	cin>>n>>t;
	vector<int> hang(n+10),lie(n+10);
	set<vector<int> > se;
	vector<vector<int> > ans(n+10,vector<int>(n+1));
	vector<int> vis(n+10);
	// vector<>
	for(int i=1;i<=n;i++){
		hang[i]=i,lie[i]=i;
	}
	for(int i=1;i<=n;i++){
		vector<int> vec;
		vec.push_back(0);
		for(int j=i;j<i+n;j++){
			int x=j%n;
			if(!x) x=n;
			vec.push_back(x);
		}
		se.insert(vec);
	}
	for(int i=1;i<=t;i++){
		char op;
		int x,y;
		cin>>op>>x>>y;
		if(op=='R'){
			swap(hang[x],hang[y]);
		}
		else{
			swap(lie[x],lie[y]);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans[i]=*se.begin();
			se.erase(se.begin());
			vis[i]=1;
			if(i!=hang[i]){
				vis[hang[i]]=1;
				vector<int> vec;
				vec.push_back(0);
				for(int j=1;j<=n;j++){
					ans[hang[i]][lie[j]]=ans[i][j];
				}
				if(!se.count(vec)){
					cout<<"*\n";
					return;
				}
				else{
					se.erase(vec);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans[i][j]<<" \n"[j==n];
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