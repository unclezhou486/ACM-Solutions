#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	vector<vector<int> > r(n+10,vector<int>(30,n+1));
	// array<int> id((),0);
	vector<int> id(1<<20,n+1);
	id[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]--;
	}
	for(int i=n-1;i>=0;i--){
		r[i][a[i+1]]=i+1;
		for(int j=0;j<20;j++){
			if(j==a[i+1]) continue;
			r[i][j]=r[i+1][j];
		}
	}
	int ans=0;
	for(int i=0;i<(1<<20);i++){
		int res=0;
		for(int j=0;j<20;j++){
			if((i>>j)&1){
				res+=2;
				id[i]=min(r[r[id[i^(1<<j)]][j]][j],id[i]);
			}
		}
		if(id[i]!=n+1){
			ans=max(ans,res);
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