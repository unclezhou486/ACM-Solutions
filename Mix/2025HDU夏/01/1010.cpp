#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		vector<int> cnt0(2*n+10),cnt1(2*n+10);
		int pre=n;
		cnt0[pre]=1;
		for(int j=1;j<=n;j++){
			if(a[j]>a[i]) pre+=1;
			else if(a[j]<a[i]) pre-=1;
			if(j<i){
				if(j&1)cnt1[pre]+=(j+1);
				else cnt0[pre]+=(j+1);
			}
			if(j>=i){
				ans+=1ll*j*a[i]*((j%2)?cnt0[pre]:cnt1[pre]);
			}
		}
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