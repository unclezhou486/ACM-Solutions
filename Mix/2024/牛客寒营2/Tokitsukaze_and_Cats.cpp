#include <bits/stdc++.h>

using namespace std;

bool v[310][310];

int ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		ans+=(!v[x][y-1])+!v[x-1][y]+!v[x+1][y]+!v[x][y+1]; 
		v[x][y]=1;
	}	
	cout<<ans<<'\n';
}