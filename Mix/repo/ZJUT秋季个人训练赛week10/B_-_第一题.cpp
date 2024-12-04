#include <bits/stdc++.h>

using namespace std;

const int N=1000;

int dp[1005][130];//time hight -> max energy

struct node{
    int t,f,h;
    bool operator < (const node &a) const {
        return t<a.t;
    }
}a[110];

void solve(){
    memset(dp,-1,sizeof dp);
	int d,g;
	cin>>d>>g;
    for(int i=1;i<=g;i++){
        cin>>a[i].t>>a[i].f>>a[i].h;
    }
    sort(a+1,a+1+g);
	dp[0][0]=10;
	for(int i=1;i<=g;i++){
		// int t,f,h;
        auto [t,f,h]=a[i];
		// cin>>t>>f>>h;
		for(int j=N;j>=0;j--){
			for(int k=100;k>=0;k--){
				if(dp[j][k]==-1) continue;
                dp[t][k+h]=max(dp[t][k+h],dp[j][k]-(t-j));
                if(dp[j][k]-(t-j)>=0)dp[t][k]=max(dp[t][k],dp[j][k]+f-(t-j));
			}
		}

        // for(int j=0;j<=t;j++){
        //     for(int k=0;k<=100;k++){
                
        //     }
        // }
		// for(int j=1;j<=N;j++){
		// 	for(int k=0;k<=125;k++){
		// 		dp[j][k]=max(dp[j][k+h],dp[j-1][k]-1);
		// 	}
		// }
	}
	int ans=2000;
	for(int i=d;i<=d+25;i++){

		for(int j=0;j<=N;j++){
			if(~dp[j][i]){
				ans=min(ans,j);
			}
		}
	}
	if(ans!=2000){
		cout<<ans<<'\n';
		return;
	}
	ans=0;
	for(int i=0;i<=d;i++){
		for(int j=0;j<=N;j++){
			if(~dp[j][i]){
                ans=max(ans,j+dp[j][i]);
            }
        }
	}
	cout<<ans<<'\n';
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
/*
100 4
5 4 9
9 3 2
12 6 10
13 1 1

*/