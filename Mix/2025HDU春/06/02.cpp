#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	long long x;
	cin>>n>>x;
	vector<long long> a(n+10),b(n+10);
	vector<long long> pre(n+10);
	vector<vector<int> > st(n+10,vector<int>(20)),to(n+10,vector<int>(20));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1) b[i]=abs(a[i]-a[i-1]);
		pre[i]=pre[i-1]+b[i];
		st[i][0]=a[i];
		to[i][0]=i+1;
	}
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			to[i][j]=to[to[i][j-1]][j-1];
			st[i][j]=max(st[i][j-1],st[to[i][j-1]][j-1]);
		}
	}
	auto get_max = [&](int l,int r) -> int {
		int len=(r-l+1);
		int t=log2(len);
		return max(st[l][t],st[r-(1<<t)+1][t]);
	};
	if(pre[n]<=x){
		cout<<0<<'\n';
		return;
	}
	auto check = [&](int len) -> bool{
		long long ress=0;
		for(int i=1;i+len-1<=n;i++){
			ress=pre[n]-(pre[i+len-1]-pre[i-1]);
			int maxnum=get_max(i,i+len-1);
			if(i!=1) ress+=abs(maxnum-a[i-1]);
			if(i+len-1!=n){
				ress-=b[i+len];
				ress+=abs(maxnum-a[i+len]);
			}
			if(ress<=x) return true;
		}
		return false;
	};
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
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