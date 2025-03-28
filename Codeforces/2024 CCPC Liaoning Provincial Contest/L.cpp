#include<bits/stdc++.h>

using namespace std;

long long check(long long x){
	long long y=x;
	long long res=0;
	for(int i=1;i<=9;i++){
		res+=x/4-x/100;
		x/=100;
	}
	return y-res;
}

void solve(){
	long long n;
	cin>>n;
	long long l=2025,r=2e18;
	while(l<r){
		long long mid=(l+r)>>1;
		if(check(mid)-check(2024)>=n) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
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
