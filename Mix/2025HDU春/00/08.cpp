#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	string op;
	int cnt0=0,cnt1=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op=="Au"){
			ans+=1;
		}
		else if(op=="Ag"){
			cnt0+=1;
		}
		else if(op=="Cu"){
			cnt1+=1;
		}
	}
	cout<<ans+min(cnt0,cnt1)<<'\n';
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