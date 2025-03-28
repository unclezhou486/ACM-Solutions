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
		int n,m,k;
		n=rand()%5+1,m=rand()%5+1,k=rand()%20+1;
		if(k==1) k+=1;
		cout<<n<<' '<<m<<' '<<k<<'\n';
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if((i==1&&j==1)||(i==n&&j==m)){
					int x=rand()%10;
					cout<<x;
				}
				else{
					int x=rand()%13;
					if(x==10){
						cout<<'+';
					}
					else if(x==11){
						cout<<'-';
					}
					else if(x==12){
						cout<<'*';
					}
					else{
						cout<<x;
					}
				}
			}
			cout<<'\n';
		}
	}
}
