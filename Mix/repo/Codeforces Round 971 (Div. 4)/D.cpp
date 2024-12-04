#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=2e5+10;

struct node{
	int x,y;
}a[N];

bool vis[N][2];

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		vis[a[i].x][a[i].y]=1;
	}
	long long ans=0;
	for(int i=0;i<=n;i++){
		if(vis[i][0]&&vis[i][1]){
			ans+=n-2;
		}
		if(i>0&&vis[i][0]&&vis[i-1][1]&&vis[i+1][1]){
			ans+=1;
		}
		if(i>0&&vis[i][1]&&vis[i-1][0]&&vis[i+1][0]){
			ans+=1;
		}
	}
	for(int i=1;i<=n;i++){
		vis[a[i].x][a[i].y]=0;
	}
	cout<<ans<<'\n';
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