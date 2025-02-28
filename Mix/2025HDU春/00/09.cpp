#include <bits/stdc++.h>

using namespace std;

constexpr int N=40000;

int A[N][40];

bool dp[N],dpp[N];

int n,a,x;

int _or(int x,int y){
	int res=0;
	for(int i=17-1;i>=0;i--){
		int ress=0;
		ress=min(A[x][i],A[y][i]);
		res*=a;
		res+=ress;
	}
	return res;
}


int _and(int x,int y){
	int res=0;
	for(int i=17-1;i>=0;i--){
		int ress=0;
		ress=max(A[x][i],A[y][i]);
		res*=a;
		res+=ress;
	}
	return res;
}


int _xor(int x,int y){
	int res=0;
	for(int i=17-1;i>=0;i--){
		int ress=0;
		ress=(A[x][i]+A[y][i])%a;
		res*=a;
		res+=ress;
	}
	return res;
}

void solve(){
	cin>>n>>a>>x;
	for(int i=0;i<40000;i++){
		int xx=i;
		for(int j=0;j<17;j++){
			A[i][j]=xx%a;
			xx/=a;
		}
	}
	for(int i=0;i<40000;i++){
		dp[i]=dpp[i]=0;
	}
	dpp[x]=1;
	for(int i=1;i<=n;i++){
		int y;
		cin>>y;
		for(int j=0;j<40000;j++){
			if(dpp[j]){
				dp[_or(j,y)]=1;
				dp[_and(j,y)]=1;
				dp[_xor(j,y)]=1;
			}
		}
		for(int j=0;j<40000;j++){
			dpp[j]=dp[j];
			dp[j]=0;
		}
	}
	long long ans=0;
	for(int i=0;i<40000;i++){
		if(dpp[i]) ans+=i;
	}
	cout<<ans<<'\n';
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}