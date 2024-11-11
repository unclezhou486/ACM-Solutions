#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;

void solve(){

}

signed main(){
	system("g++ bad.cpp -O2 -std=c++17 -o bad");
	system("g++ good.cpp -O2 -std=c++17 -o good");
	system("g++ shuju.cpp -O2 -std=c++17 -o shuju");
	for(int i=1;i<=1000;i++){
		system("./shuju > 1.out");
		system("./bad < 1.out > bad.out");
		system("./good < 1.out > good.out");
		int x=system("diff bad.out good.out");
		if(x){
			cout<<"WA";
			break;
		}
		else cout<<"AC";
		cout<<' '<<i<<'\n';
	}
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// int t=1;
	// cin>>t;
	// while(t--){
	// 	solve();
	// }
	// return 0;
}