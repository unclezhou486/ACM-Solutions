// 1     22  23     43
// 43    22  21     1

//1 2 3 4 5
//5 4 3 2 1

//(n+1)*(n/2)+1

//1 2 3 4
//4 3 2 1

//n*n/2+1

#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	if(n%2){
		cout<<(n+1)*(n/2)/2+1<<'\n';
	}
	else{
		cout<<n*(n/2)/2+1<<'\n';
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