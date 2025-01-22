#include <bits/stdc++.h>

using namespace std;

int suma,sumb;

void sol(int x){
	if(x==1||x==4) suma+=x;
	else sumb+=x;
}

void solve(){
	int a,b;
	cin>>a>>b;
	bool flag=false;
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			for(int k=1;k<=6;k++){
				suma=0,sumb=0;
				sol(i);
				sol(j);
				sol(k);
				if(suma==a&&sumb==b){
					flag=true;
				}
			}
		}
	}
	if(flag){
		cout<<"Yes\n";
	}
	else cout<<"No\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}