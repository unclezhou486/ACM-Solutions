#include <bits/stdc++.h>

using namespace std;

constexpr int MOD=998244353;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<char> > a;
	if(n>=m){
		a.assign(n+5,vector<char>(m+5));	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				if(a[i][j]!='?') a[i][j]-=1;
			}
		}
	}
	else{
		a.assign(m+5,vector<char>(n+5));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[j][i];
				if(a[j][i]!='?') a[j][i]-=1;
			}
		}
		swap(n,m);
	}
	long long res=pow(3,m);
	long long ress=pow(3,m-1);
	vector<long long> dis(res);
	vector<pair<int,int> > dp,dpp;
	dp.push_back({0,1}); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='?'){
				for(int k=0;k<3;k++){
					for(auto [x,cnt]:dp){
						if(i!=1){
							if(x/ress==k) continue;
						}
						if(j!=1){
							if(x%3==k) continue;
						}
						int y=(x-x/ress*ress)*3+k;
						dis[y]=(dis[y]+cnt)%MOD;
					}
				}
			}
			else{
				int k=a[i][j]-'0';
				for(auto [x,cnt]:dp){
					if(i!=1){
						if(x/ress==k) continue;
					}
					if(j!=1){
						if(x%3==k) continue;
					}
					int y=(x-x/ress*ress)*3+k;
					dis[y]=(dis[y]+cnt)%MOD;
				}
			}
			for(auto [x,cnt]:dp){
				for(int k=0;k<3;k++){
					int y=(x-x/ress*ress)*3+k;
					if(dis[y]){
						dpp.push_back({y,dis[y]});
						dis[y]=0;
					}
				}
			}
			swap(dp,dpp);
			dpp.clear();
		}
	}
	long long ans=0;
	for(auto[x,cnt]:dp){
		ans=(ans+cnt)%MOD;
	}
	cout<<ans<<'\n';
	// vector<int> b(m+5);
	// vector<vector<long long> > qu(10);
	// vector<long long> statu;
	// for(int i=0;i<res;i++){
	// 	int x=i;
	// 	bool flag=1;
	// 	for(int j=1;j<=m;j++){
	// 		b[j]=x%3;
	// 		x/=3;
	// 		if(j!=1&&b[j]==b[j-1]){
	// 			flag=0;
	// 		}
	// 	}
	// 	if(flag)qu[b[1]*3+b[m]].push_back(i),statu.push_back(i);
	// }
	// vector<long long> dp(res);
	// vector<long long> dpp(res);
	// dp[0]=1;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		for(auto x:statu){
	// 			dpp[x]=0;
	// 		}
	// 		if(a[i][j]=='?'){
	// 			for(int k=0;k<=2;k++){
	// 				for(int l=0;l<=2;l++){
	// 					for(int xx=0;xx<=2;xx++){
	// 						if(xx==k||xx==l) continue;
	// 						for(auto x:qu[k*3+l]){
	// 							int y=(x-k*ress)*3+xx;
	// 							dpp[y]=(dpp[y]+dp[x])%MOD;
	// 						}
	// 					}
	// 				}
	// 			}
	// 		}
	// 		else{
	// 			int xx=a[i][j]-'0';
	// 			for(int k=0;k<=2;k++){
	// 				for(int l=0;l<=2;l++){
	// 					if(k==xx||k==l) continue;
	// 					for(auto x:qu[k*3+l]){
	// 						int y=(x-k*ress)*3+xx;
	// 						dpp[y]=(dpp[y]+dp[x])%MOD;
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// 	for(auto x:statu){
	// 		dp[x]=dpp[x];
	// 	}
	// }
	// long long ans=0;
	// for(auto x:statu){
		// ans=(ans+dp[x])%MOD;
	// }
	// cout<<ans<<'\n';
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