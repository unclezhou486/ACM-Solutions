#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	vector<int> x(n+10),y(n+10);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	int d;
	cin>>d;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(x[i]+y[i]<c){
			x[i]=min(x[i]+d,a);
			if(x[i]+y[i]>=c){
				ans+=1;
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
