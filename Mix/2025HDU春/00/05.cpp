#include<bits/stdc++.h>
#define int long long

using namespace std;


void solve(){
	int n,m,q;
	cin>>n>>m;
	vector<int> a(n+10);
	vector<vector<int> > vec(m);
	vector<long long> dp(n+10,1e18);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vec[a[i]%m].push_back(a[i]/m);
	}
	dp[n]=0;
	for(int i=0;i<m;i++){
		int nn=vec[i].size();
		if(!nn) continue;
		sort(vec[i].begin(),vec[i].end());
		vector<vector<long long> > dpp(nn+10,vector<long long>(nn+10,1e18));
		vector<long long> pre(nn+10);
		dpp[0][0]=0;
		for(int j=1;j<=nn;j++){
			pre[j]=pre[j-1]+vec[i][j-1];
			for(int k=0;k<j;k++){//[k+1,j] same
				int resid=(k+1+(j-(k+1)+1+1)/2-1);
				int resl=k+1,resr=j; 
				long long val=vec[i][resid-1]*(resid-resl+1)-(pre[resid]-pre[resl-1])+(pre[resr]-pre[resid])-(vec[i][resid-1]*(resr-resid));
				for(int l=0;l<=k;l++){
					dpp[j][l+1]=min(dpp[j][l+1],dpp[k][l]+val);
				}
			}
		}
		vector<long long> weight(nn+10,1e18);
		for(int i=1;i<=nn;i++){
			weight[nn-i]=dpp[nn][i];
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=nn;j++){
				if(i+j<=n)dp[i]=min(dp[i],dp[i+j]+weight[j]);
			}
		}
	}
	long long ans=0;
	cin>>q;
	for(int i=1;i<=q;i++){
		long long x;
		cin>>x;
		int l=0,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(dp[mid]>x) l=mid;
			else r=mid-1;
		}
		ans=(ans*13331+l+1)%998244353;
	}
	// int id=1;
	// for(int i=n;i>=0;i--){
	// 	while(id<=q&&que[id].x<dp[i]){
	// 		ans[que[id].id]=i+1;
	// 		id+=1;
	// 	}
	// }
	// long long anss=0;
	// for(int i=1;i<=q;i++){
	// 	anss=(anss*13331+ans[i])%998244353;
	// }
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
