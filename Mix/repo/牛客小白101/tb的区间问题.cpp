#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;

int n,k;

long long a[N],pre[N];

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	long long ans=0;
	k=n-k;
	for(int i=k;i<=n;i++){
		ans=max(ans,pre[i]-pre[i-k]);
	}
	cout<<ans<<'\n';
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