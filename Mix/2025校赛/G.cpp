#include<bits/stdc++.h>
// #define int long long

using namespace std;

constexpr int mod=998244353;

void solve(){
	int n,m,d;
	cin>>n>>m>>d;
	vector<vector<int>  >from(n+10);
	vector<vector<int> > to(n+10);
	vector<int> deg(n+10);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		from[v].push_back(u);
		to[u].push_back(v);
	}
	for(int i=1;i<n;i++){
		if(to[i].size()>d){
			cout<<0<<'\n';
			return;
		}
	}
	for(int i=2;i<=n;i++){
		if(!from[i].size()){
			cout<<0<<'\n';
			return;
		}
		else{
			sort(from[i].begin(),from[i].end(),greater<>());
			for(int j=0;j<from[i].size();j++){
				if(from[i][j]!=(i-j-1)){
					cout<<0<<'\n';
					return;
				}
			}
			deg[from[i].back()]+=1;
		}
	}
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(deg[i]>1){
			cout<<0<<'\n';
			return;
		}
		else if(deg[i]==0){
			cnt++;
		}
	}
	if(cnt>d){
		cout<<0<<'\n';
		return;
	}
	long long ans=d;
	ans%=mod;
	for(int i=0;i<cnt;i++){
		ans=ans*(d-i)%mod;
	}
	cout<<ans<<'\n';
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

/*
1
6 9 2
1 2
1 3
2 3
2 4
3 4
3 5
4 5
4 6
5 6


*/