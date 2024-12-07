#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	long long ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			swap(s[i],s[j]);
			long long res=0;
			for(int k=0;k<n;k++){
				res*=10;
				res+=s[k]-'0';
			}
			swap(s[i],s[j]);
			ans=max(ans,res);
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