#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(a[i]==b[i]&&a[i]=='o'){
			flag=true;
		}
	}	
	cout<<(flag?"Yes\n":"No\n");
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