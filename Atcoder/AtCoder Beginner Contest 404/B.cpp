#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<vector<int> > a(n+10,vector<int>(n+10)),b(n+10,vector<int>(n+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char ch;
			cin>>ch;
			a[i][j]=(ch=='.');
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char ch;
			cin>>ch;
			b[i][j]=(ch=='.');
		}
	}
	auto change = [&] (vector<vector<int> > &a){
		vector<vector<int> > c(n+10,vector<int>(n+10));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[j][n-i+1]=a[i][j];
			}
		}
		a=c;
	};
	int ans=1e9;
	for(int op=0;op<4;op++){
		int res=op;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				// cout<<b[i][j]<<" \n"[j==n];
				if(a[i][j]!=b[i][j]){
					res++;
				}
			}
		}
		ans=min(ans,res);
		change(a);
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