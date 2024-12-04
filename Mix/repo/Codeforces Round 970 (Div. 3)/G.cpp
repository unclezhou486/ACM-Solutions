#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,k;

long long a[N];

long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}

void solve(){
	cin>>n>>k;
	long long gd=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		gd=gcd(gd,a[i]);
	}
	if(n>1){
		for(int i=1;i<=n;i++){
			a[i]=(i-1)*gd;
		}	
	}
	a[n+1]=1e18;
	for(int i=1;i<=n+1;i++){
		// cout<<a[i]<<" \n"[i==n+1];
		if(k<=a[i]){
			cout<<k-1<<'\n';
			return;
		}
		else{
			k+=1;
		}
	}
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