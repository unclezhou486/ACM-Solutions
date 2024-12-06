#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<int> > a(n+10,vector<int>(n+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[i][k]>a[i-1][k]&&a[i][k]>a[i][k-1]&&a[i][k]>a[i][k+1]&&a[i][k]>a[i+1][k]){
					int res=max(a[i-1][k],max(a[i][k-1],max(a[i][k+1],a[i+1][k])));
					if(res<=0) a[i][k]=0;
					else{
						cout<<"NO\n";
						return;
					}
				}
				else if(a[i][k]<a[i-1][k]&&a[i][k]<a[i][k-1]&&a[i][k]<a[i][k+1]&&a[i][k]<a[i+1][k]){
					int res=min(a[i-1][k],min(a[i][k-1],min(a[i][k+1],a[i+1][k])));
					if(res>=0) a[i][k]=0;
					else{
						cout<<"NO\n";
						return;
					}
				}
			}
		}
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=0){
				flag=false;
			}
		}
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
	// cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
	return 0;
}