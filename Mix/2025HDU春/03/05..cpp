#include <bits/stdc++.h>

using namespace std;

constexpr int N=3e5+10;

int f[N];
int n;

int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) f[i]=i;
	int ans=n-1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int y=i-x;
		if(y>=1&&y<=n){
			if(find(y)!=find(i)){
				f[find(y)]=find(i);
				ans-=1;
			}
		}
		y=i+x;
		if(y>=1&&y<=n){
			if(find(y)!=find(i)){
				f[find(y)]=find(i);
				ans-=1;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
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