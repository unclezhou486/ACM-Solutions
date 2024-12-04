#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=2e5+10;

int n;
int pre[N][30][2];
//1 2 3 4 5 6 7
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		pre[i][a-'a'+1][i%2]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			for(int k=0;k<2;k++){
				pre[i][j][k]+=pre[i-1][j][k];		
			}
		}
	}
	int ans=1e9;
	if(n%2){
		for(int i=1;i<=n;i++){
			int res1=0,res2=0;
			for(int j=1;j<=26;j++){
				res1=max(res1,pre[i-1][j][0]+(pre[n][j][1]-pre[i][j][1]));
				res2=max(res2,pre[i-1][j][1]+(pre[n][j][0]-pre[i][j][0]));
			}
			ans=min(ans,n-res1-res2);
		}
	}
	else{
		int res1=0,res2=0;
		for(int i=1;i<=26;i++){	
			res1=max(res1,pre[n][i][0]);
			res2=max(res2,pre[n][i][1]);	
		}
		ans=min(ans,n-res1-res2);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			for(int k=0;k<2;k++){
				pre[i][j][k]=0;				
			}
		}
	}
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