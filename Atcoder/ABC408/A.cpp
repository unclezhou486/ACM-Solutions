#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,s;
	cin>>n>>s;
	int la=0;
	bool ans=true;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ans&=(x-la <=s);
		la=x;
	}
	cout<<(ans?"Yes\n":"No\n");
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