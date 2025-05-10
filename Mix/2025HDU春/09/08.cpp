#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n+10);
	vector<vector<int>> pre(n+10,vector<int>(n+10));
	vector<vector<int> > maxx(n+10,vector<int>(n+10)),minx(n+10,vector<int>(n+10,2e9));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			maxx[i][j]=max(maxx[i][j-1],a[j]);
			minx[i][j]=min(minx[i][j-1],a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			int l=j+1,r=n;
			int res=maxx[i][j];
			while(l<r){
				int mid=(l+r+1)>>1;
				if(minx[j+1][mid]>=res) l=mid;
				else r=mid-1;
			}
			if(minx[j+1][l]>=res){
				pre[i][j+1]+=1;
				pre[i][l+1]-=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pre[i][j]+=pre[i][j-1];
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<pre[l][r]<<'\n';
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