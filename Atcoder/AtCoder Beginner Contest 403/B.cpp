#include<bits/stdc++.h>

using namespace std;

void solve(){
	string t,u;
	cin>>t>>u;
	int n=t.size(),m=u.size();
	for(int i=0;i+m-1<n;i++){
		bool flag=true;
		for(int j=i;j<=i+m-1;j++){
			if(t[j]=='?'||t[j]==u[j-i]) continue;
			flag=false;
			break;
		}
		if(flag){
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
	return;
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
