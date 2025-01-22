#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n,l,r;
	cin>>n>>l>>r;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	map<int,int> ma;
	for(int i=1;i<=r;i++){
		ma[a[i]]+=1;
	}
	int res=0;
	int len=r-l+1;
	int cnt=0;
	for(auto [x,y]:ma){
		int ress=min(len-cnt,y);
		res+=x*ress;
		cnt+=ress;
		if(cnt==len) break;
	}
	int ans=res;
	res=0;
	map<int,int> maa;
	for(int i=l;i<=n;i++){
		maa[a[i]]+=1;
	}
	res=0;
	cnt=0;
	len=r-l+1;
	for(auto [x,y]:maa){
		int ress=min(len-cnt,y);
		res+=x*ress;
		cnt+=ress;
		if(cnt==len) break;
	}
	ans=min(ans,res);
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