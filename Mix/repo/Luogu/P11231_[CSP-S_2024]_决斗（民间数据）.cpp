#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int a[N];

map<int,int> ma;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ma[x]+=1;
	}
	int res=0;
	int ans=0;
	for(auto [x,y]:ma){
		int ress=min(res,y);
		ans+=ress;
		res=res+y-ress;
	}
	cout<<n-ans<<'\n';
}