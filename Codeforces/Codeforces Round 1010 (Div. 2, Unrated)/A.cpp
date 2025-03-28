#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > a(n+10,vector<int>(m+10));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;
			cin>>ch;
			a[i][j]=ch-'0';
		}
	}
	int res1=0,res2=0;
	vector<int> line(n+10),row(m+10);
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=1;j<=m;j++){
			res^=a[i][j];
		}
		if(res) line[i]=1,res1+=1;
	}
	for(int i=1;i<=m;i++){
		int res=0;
		for(int j=1;j<=n;j++){
			res^=a[j][i];
		}
		if(res) row[i]=1,res2+=1;
	}
	// int ans=0;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		if(line[i]&&row[j]){
	// 			line[i]=0,row[j]=0;
	// 			ans+=1;
	// 		}
	// 	}
	// }
	// cout<<ans<<'\n';
	cout<<max(res1,res2)<<'\n';
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
