#include <bits/stdc++.h>

using namespace std;

void solve(){
	int k;
	string s,r;
	cin>>k>>s>>r;
	int n=s.size(),m=r.size();
	int ans=0;
	for(int i=0;i+m-1<n;i++){
		int res=0;
		for(int j=i;j<=i+m-1;j++){
			if(s[j]!=r[j-i]){
				res+=1;
			}
		}
		// cout<<i<<' '<<res<<'\n';
		if(res==k){
			ans+=1;
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