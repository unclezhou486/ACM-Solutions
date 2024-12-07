#include <bits/stdc++.h>
#define int long long
using namespace std;



void solve(){
	vector<vector<long long> > a(10,vector<long long> (10,1e18));
	for(int i=1;i<=3;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	int ress=3*a[2][2];
	for(int l=1;l<=9;l++){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]!=1e18){
					a[4-i][4-j]=2*a[2][2]-a[i][j];
				}
			}
		}
		for(int i=1;i<=3;i++){
			long long res=0;
			int cnt=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]!=1e18){
					cnt++;
					res+=a[i][j];
				}
			}
			if(cnt==2){
				for(int j=1;j<=3;j++){
					if(a[i][j]==1e18){
						a[i][j]=ress-res;
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			int res=0;
			int cnt=0;
			for(int j=1;j<=3;j++){
				if(a[j][i]!=1e18){
					cnt++;
					res+=a[j][i];
				}
			}
			if(cnt==2){
				for(int j=1;j<=3;j++){
					if(a[j][i]==1e18){
						a[j][i]=ress-res;
					}
				}
			}
		}
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(a[i][j]==1e18){
				a[i][j]=(a[2][4-j]+a[4-i][2])/2;
			}
		}
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cout<<a[i][j]<<" ";
		}
	}
	cout<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}