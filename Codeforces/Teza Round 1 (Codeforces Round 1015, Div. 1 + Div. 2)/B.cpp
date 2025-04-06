#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long gd=0;
	long long minx=1e18;
	int id=-1;
	for(int i=1;i<=n;i++){
		// gd=gcd(a[i],gd);
		// minx=min(a[i],minx);
		if(a[i]<minx){
			minx=a[i];
			id=i;
		}
	}

	for(int i=1;i<=n;i++){
		if(i==id) continue;
		if(a[i]%minx==0){
			gd=gcd(gd,a[i]);
		}
	}
	if(minx==gd){
		cout<<"Yes\n";
	}
	else cout<<"No\n";
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
