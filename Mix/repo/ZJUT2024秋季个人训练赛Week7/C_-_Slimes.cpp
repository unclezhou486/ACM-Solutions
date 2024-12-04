#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n+10),pre(n+10),b(n+10),preb(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=abs(a[i]-a[i-1]);
		pre[i]=a[i]+pre[i-1];
		preb[i]=b[i]+preb[i-1];
	}
	// for(int i=n;i>=1;i--){
	// 	maxn[i][0]=a[i];
	// 	go[i][0]=i+1;
	// 	for(int j=1;j<20;j++){
	// 		maxn[i][j]=max(maxn[i][j],maxn[go[i][j-1]][j-1]);
	// 	}
	// }
	// auto ask_max = [&] (int l,int r) -> long long {
	// 	int len=(r-l+1);
	// 	int tmp=log2(len);
	// 	return max(maxn[l][tmp],maxn[r-(1<<tmp)+1][tmp]);
	// };
	auto check = [&] (int l,int r,int x) -> bool {
		long long res=pre[r]-pre[l-1];
		long long ress=preb[r]-preb[l];
		if(res>x&&ress) return 1;
		else return 0;
	};
	vector<int> ans(n+10,1e9);
	for(int i=1;i<=n;i++){
		if(i>1){
			if(a[i-1]>a[i]){
				ans[i]=1;
				continue;
			}
			int l=1,r=i-1;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(check(mid,i-1,a[i])) l=mid;
				else r=mid-1;
			}
			if(check(l,i-1,a[i])){
				ans[i]=min(ans[i],i-l);
			}
		}
		if(i<n){
			if(a[i+1]>a[i]){
				ans[i]=1;
				continue;
			}
			int l=i+1,r=n;
			while(l<r){
				int mid=(l+r)>>1;
				if(check(i+1,mid,a[i])) r=mid;
				else l=mid+1;
			}
			if(check(i+1,l,a[i])){
				ans[i]=min(ans[i],l-i);
			}
		}
		if(ans[i]==1e9) ans[i]=-1;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
	}
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