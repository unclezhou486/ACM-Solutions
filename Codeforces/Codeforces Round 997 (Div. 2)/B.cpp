#include <bits/stdc++.h>

using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<vector<int> > a(n+10,vector<int>(n+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char ch;
			cin>>ch;
			a[i][j]=ch-'0';
		}
	}
	vector<int> p(n+1);
	for(int i=1;i<=n;i++) p[i]=i;
	auto cmp = [&] (int x,int y) -> bool {
		if(a[x][y]) return x<y;
		else return x>y;
	};
	sort(p.begin()+1,p.end(),cmp);
	for(int i=1;i<=n;i++){
		cout<<p[i]<<" \n"[i==n];
	}
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