#include <bits/stdc++.h>

using namespace std;

void solve(){
	int t,n,m;
	cin>>t>>n>>m;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+1+n);
	int res=0;
	for(int i=1;i<=m;i++){
		res+=a[i];
	}
	t-=res;
	int ans=0;
	if(t>=0){
		ans=t/40;
	}
	else{
		ans=-1;
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