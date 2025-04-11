#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a,b,c(n+10);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='R') a.push_back(c[i]);
		else b.push_back(c[i]);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	long long ans=0;
	if(a.size()>b.size()){
		for(int i=0;i<b.size();i++){
			ans+=a[i]+b[i];
		}
		ans+=a[b.size()];
	}
	else{
		for(int i=0;i<a.size();i++){
			ans+=a[i]+b[i];
		}
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