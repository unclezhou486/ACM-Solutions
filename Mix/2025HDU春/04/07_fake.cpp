#include <bits/stdc++.h>

using namespace std;

constexpr int N=10;
bool dp[N][N][N][N];
bool vis[N][N][N][N];
bool sol(int ax,int ay,int bx,int by){
	if(ax==0&&ay==0){
		return true;
	}
	else if(bx==0&&by==0){
		return false;
	}
	if(vis[ax][ay][bx][by]) return dp[ax][ay][bx][by];
	bool flag=false;
	vector<int> a(2),b(2);
	// a[0]=ax,a[1]=ay;
	// b[0]=bx,b[1]=by;
	if(ax){
		if(bx)if(!sol(bx,by,(ax+bx)%10,ay)) flag=true;
		if(by)if(!sol(bx,by,(ax+by)%10,ay)) flag=true;
	}
	if(ay){
		if(bx)if(!sol(bx,by,ax,(ay+bx)%10)) flag=true;
		if(by)if(!sol(bx,by,ax,(ay+by)%10)) flag=true;
	}
	vis[ax][ay][bx][by]=1;
	return dp[ax][ay][bx][by]=flag;
}

void solve(){
	int ax,ay,bx,by;
	cin>>ax>>ay>>bx>>by;
	cout<<sol(ax,ay,bx,by)<<'\n';
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