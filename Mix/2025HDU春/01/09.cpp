#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+10);
	vector<int> g((1<<m));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<(1<<m);i++){
		cin>>g[i];
	}
	vector<tuple<long long ,int ,int> > vec,tmp;
	vector<long long> dp(n+10,-1e18);
	
	dp[0]=0;
	vec.push_back({0,(1<<m)-1,0});

	for(int i=1;i<=n;i++){
		long long res=-1e18;
		for(auto &[x,y,z]:vec){
			y&=a[i];
			z|=a[i];
			res=max(res,x+(g[z-y]));
		}
		tmp=vec,vec.clear();
		for(auto &[x,y,z]:tmp){
			if(vec.empty()||get<1>(vec.back())!=y||get<2>(vec.back())!=z){
				vec.push_back({x,y,z});
			}
			else{
				auto &[xx,yy,zz]=vec.back();
				xx=max(x,xx);
			}
			
		}
		dp[i]=res;
		vec.push_back({dp[i],(1<<m)-1,0});
	}	
	cout<<dp[n]<<'\n';
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
