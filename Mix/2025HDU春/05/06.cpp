#include <bits/stdc++.h>

using namespace std;



void solve(){
	int d,r,x,y;
	cin>>d>>r>>x>>y;
	if(y>=d||y<=-d){
		y=abs(y);
		double dis=(y-d)*(y-d)+x*x;
		double ans=0;
		if(dis>r*r){
			ans=sqrt(dis)-r;
		}
		else{
			ans=r-sqrt(dis);
		}
		cout<<round(ans)<<'\n';
	}
	else{
		cout<<min(abs(x+r),abs(x-r))<<'\n';
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