#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	// cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
	// return;
	int ans=0;
	if(a<4){
		cout<<0<<'\n';
		return;
	}
	for(int i=1;i<=d/i;i++){
		if(i*2<=b&&i*2<=c){
			// ans=max(ans,4+i*2+i*2+i*i);
			for(int j=i*i,ress=i*2;j<=d;j+=i,ress+=1){
				if(ress<=b&&ress<=c){
					ans=max(ans,4+ress+ress+j);
				}
			}
		}
	}
	ans=max(ans,4+min(b,c)*2);
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