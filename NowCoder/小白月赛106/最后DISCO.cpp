#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b==0){
		if((c+d)%2){
			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
	}
	else{
		a=a%2;
		c=c%2,d=d%2;
		if((a*c+d)%2){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
	return 0;
}