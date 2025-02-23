#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n+10);
	vector<long long> pre1(n+10),pre2(n+10);
	long long res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre1[i]=pre1[i-1];
		if(a[i]>=0){
			pre1[i]+=a[i];
		}
	}
	for(int i=n;i>=1;i--){
		pre2[i]=pre2[i+1];
		if(a[i]<=0){
			pre2[i]+=-a[i];
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,pre1[i]+pre2[i]);
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