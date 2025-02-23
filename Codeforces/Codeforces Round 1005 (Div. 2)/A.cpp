#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int res=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if((s[i]-'0')!=res){
			res=1-res;
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