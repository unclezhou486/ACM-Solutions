#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a[20];
	map<int,int> ma;
	for(int i=1;i<=9;i++){
		cin>>a[i];
		ma[a[i]]+=1;
	}
	int cnt=0,maxn=0;
	for(auto [x,y]:ma){
		cnt+=1;
		maxn=max(y,maxn);
	}
	if(cnt==3&&maxn==3){
		cout<<"Yes\n";
	}
	else cout<<"No\n";
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