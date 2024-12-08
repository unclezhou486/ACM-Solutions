#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool ans=false;
	int ansid=-1;
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if((abs(a[i]-a[j])%k==0)) flag=false;
		}
		if(flag){
			ans=true;
			ansid=i;
		}
	}
	if(ans) cout<<"YES\n"<<ansid<<'\n';
	else{
		cout<<"NO\n";
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