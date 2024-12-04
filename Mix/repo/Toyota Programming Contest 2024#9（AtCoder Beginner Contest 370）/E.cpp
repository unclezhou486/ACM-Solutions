#include <bits/stdc++.h>

using namespace std;

const int MOD1=998244353;
const int N=2e5+10;

int n;
long long k;

int a[N];

// long long c[N<<1];

struct node{
	long long x;
	int id;
}pre[N<<1];

int b[N<<1];

long long dp[N];
long long c[N<<1];

long long sum;

bool cmp(node a,node b){
	return a.x<b.x;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i].x=(pre[i-1].x+a[i]);
		pre[i+n].x=pre[i].x-k;
		pre[i+n].id=i+n;
		pre[i].id=i;
	}
	pre[0].x=0,pre[0].id=0;
	// for(int i=0;i<=n;i++){
	// 	cout<<pre[i].x<<" \n"[i==n];
	// }
	sort(pre,pre+2*n+1,cmp);
	int cnt=0;
	b[pre[0].id]=++cnt;
	for(int i=1;i<=n*2;i++){
		if(pre[i].x==pre[i-1].x){
			b[pre[i].id]=cnt;
		}
		else{
			b[pre[i].id]=++cnt;
		}
	}
	// for(int i=0;i<=2*n;i++){
	// 	cout<<b[i]<<" \n"[i==2*n];
	// }
	// if(k) sum=0;
	sum=1;
	c[b[0]]=sum;
	for(int i=1;i<=n;i++){
		// cout<<i<<' '<<sum<<' '<<c[b[i+n]]<<'\n';
		dp[i]+=sum-c[b[i+n]];
		dp[i]%=MOD1;
		dp[i]+=MOD1;
		dp[i]%=MOD1;
		c[b[i]]+=dp[i];
		c[b[i]]%=MOD1;
		sum+=dp[i];
		sum%=MOD1;
	}
	// for(int i=1;i<=n;i++){
		// cout<<dp[i]<<" \n"[i==n];
	// }
	cout<<dp[n]%MOD1<<'\n';
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