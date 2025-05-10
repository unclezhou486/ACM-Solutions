#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> x(n+10),y(n+10);
	map<pair<int,int>,int> app;
	map<tuple<int,int,long long>,int> ma;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		x[i]*=2,y[i]*=2;
		app[{x[i],y[i]}]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int x1=x[i],y1=y[i],x2=x[j],y2=y[j];
			int x3=(x1+x2+y1-y2)/2,x4=(x1+x2+y2-y1)/2;
			int y3=(y1+y2+x2-x1)/2,y4=(y1+y2+x1-x2)/2;
			int x0=(x1+x2),y0=(y1+y2);
			long long len=1ll*(x4-x3)*(x4-x3)+1ll*(y4-y3)*(y4-y3);
			if(app.count({x3,y3})&&app.count({x4,y4}));
			ma[{x0,y0,len}]+=1;
		}
	}
	long long ans=0;
	for(auto [pos,num]:ma){
		num/=2;
		ans+=1ll*num*(num-1)/2;
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