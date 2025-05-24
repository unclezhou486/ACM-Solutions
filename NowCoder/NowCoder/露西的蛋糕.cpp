#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long n,m,x;
	cin>>n>>m>>x;
	long long res=n-m;
	if(m){
		res+=1;
		cout<<(1ll<<res)-x+1<<'\n';
	} 
	else{
		cout<<x<<'\n';
	}
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
