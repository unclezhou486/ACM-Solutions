#include <bits/stdc++.h>

using namespace std;

void solve(){
	int m;
	// cin>>m;
	scanf("%d",&m);
	
	for(int i=1;i<=m;i++){
		int h,m;
		int d;
		scanf("%d:%d",&h,&m);
		scanf("%d",&d);
		h+=d;
		h=((h%24)+24)%24;
		if(h<10){
			printf("0");
		}
		printf("%d:",h);
		if(m<10){
			printf("0");
		}
		printf("%d\n",m);
	}

}

int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t=1;
	// cin>>t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}