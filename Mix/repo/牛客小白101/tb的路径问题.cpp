#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;


int n;

void solve(){
	cin>>n;
	if(n==1) cout<<0<<'\n';
	else if(n==2){
		cout<<2<<'\n';
	}
	else if(n==3){
		cout<<4<<'\n';
	}
	else{
		if(n%2){
			cout<<6<<'\n';
		}
		else{
			cout<<4<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;

}