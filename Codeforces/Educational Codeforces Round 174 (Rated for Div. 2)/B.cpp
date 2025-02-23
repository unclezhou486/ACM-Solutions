#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > a(n+10,vector<int>(m+10));
	vector<bool> vis(n*m+10,2);
	vector<int> cnt(n*m+10);
	int sum=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bool flag=1;
			for(int k=0;k<4;k++){
				int xx=i+dx[k],yy=j+dy[k];
				if(a[xx][yy]==a[i][j]){
					flag=0;
				}
			}
			if(!flag){
				cnt[a[i][j]]=2;
			}
			else{
				if(!cnt[a[i][j]]){
					cnt[a[i][j]]=1;
				}
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		sum+=cnt[i];
		maxn=max(maxn,cnt[i]);
	}
	cout<<sum-maxn<<'\n';
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