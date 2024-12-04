#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N=2e5+10;
const int MOD=998244353;
int n,m,k;

int dp[N<<1];

struct node{
	int x,y;
}a[100];

pair<int,int> add[110];

void solve(){
	cin>>n>>m>>k;
	a[0].x=n,a[0].y=1;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y;
	}
	dp[k+1]=1;
	int left=k;
	while(k--){
		for(int i=0;i<=m;i++){
			add[i]={a[i].y,dp[left+a[i].x]};
		}
		left-=1;
		for(int i=0;i<=m;i++){
			dp[add[i].first+left]+=add[i].second;
			dp[add[i].first+left]%=MOD;
		}
		// for(int i=1;i<=n+k;i++){
			// cout<<dp[i]<<" \n"[i==n+k];
		// }
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i];
		ans%=MOD;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}