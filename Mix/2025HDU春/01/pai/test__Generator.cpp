#include<bits/stdc++.h>

using namespace std;

// void solve(){
	// 
// }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	struct timeb timer;
    ftime(&timer);
	srand(timer.time*1000+timer.millitm);
	int t=2;
	// cin>>t;
	cout<<t<<'\n';

	while(t--){
		int n,m;
		n=rand()%5+1,m=rand()%3+1;
		cout<<n<<' '<<m<<'\n';
		int res=(1<<m)-1;
		for(int i=1;i<=n;i++){
			int x;
			x=rand()%res+1;
			cout<<x<<" \n"[i==n];
		}
		for(int i=0;i<=res;i++){
			int x=rand()%10+1;
			int y=rand()%2;
			if(y) x=-x;
			cout<<x<<" \n"[i==res];
		}
	}
}
