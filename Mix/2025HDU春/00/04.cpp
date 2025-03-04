#include<bits/stdc++.h>

using namespace std;

bool check(long long a,long long b){
	if(a%b==0) return 1;
	if(b*2<=a) return 1;
	return !check(b,a-b);
}

void solve(){
	int n;
	long long x;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		long long res=x*0.6180339887498948;
		while(res>0&&!check(x,res)) --res;
		while(res+1<x&&check(x,res+1)) ++res;
		res+=1;
		ans=ans^res;
		// cout<<res<<'\n';
	}
	cout<<ans<<'\n';
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
