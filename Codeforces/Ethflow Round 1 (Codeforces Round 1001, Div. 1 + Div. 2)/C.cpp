#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	vector<int> b(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1]<<'\n';
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		while(n!=1){
			int res=0;
			for(int i=1;i<=n;i++){
				b[i]=a[i+1]-a[i];
			}
			for(int i=1;i<n;i++){
				a[i]=b[i];
				res+=b[i];
			}
			res=abs(res);
			ans=max(ans,res);
			n-=1;
		}
		cout<<ans<<'\n';
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}