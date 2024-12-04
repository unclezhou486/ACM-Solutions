#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n;

bool vis[N];

bool is[N];

bool ans[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		vis[x]=1;
	}
	if(!vis[1]){
		cout<<0<<'\n';
		return;
	}
	ans[1]=0;
	for(int i=2;i<=1000000;i++){
		if(vis[i]) continue;
		for(int j=i;j<=1000000;j+=i){
			ans[j]=1;
		}
	}
	int res=0;
	for(int i=1;i<=1000000;i++){
		if(!ans[i]) res+=1;
	}
	cout<<res<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;

}