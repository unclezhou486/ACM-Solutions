#include <bits/stdc++.h>

using namespace std;

void solve(){
	int v,w;
	cin>>v>>w;
	int x=(v/(w/2+1));
	if(!x||w-w/2-1<v-x*(w/2+1)) x+=1;
	cout<<x<<'\n';
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



//11 4

//9

//1 1 1 