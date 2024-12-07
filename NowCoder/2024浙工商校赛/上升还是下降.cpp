#include <bits/stdc++.h>

using namespace std;



void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++) cin>>a[i];
	int x=0,y=0,z=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			if(a[i]!=(n-i+1)){
				y+=1;
			}
			else{
				x+=1;
			}
		}
		else if(a[i]!=(n-i+1)){
			z+=1;
		}
	}
	// cout<<x<<' '<<y<<' '<<z<<'\n';
	if(x<z){
		if(x+y<=z) cout<<"jia\n";
		else cout<<"orz\n";
	}
	else if(x==z){
		if(y) cout<<"orz\n";
		else cout<<"jia\n";
	}
	else{
		if(z+y<x) cout<<"jian\n";
		else cout<<"orz\n";
	}
}

signed main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}