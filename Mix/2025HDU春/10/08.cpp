#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > a(n+10,vector<int>(m+10));
	vector<int> maxid(n+10),maxres(n+10),cnt(m+10);
	int ans=0;
	for(int i=1;i<=n;i++){
		maxres[i]=0;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>maxres[i]){
				maxres[i]=a[i][j];
				maxid[i]=j;
			}
		}
		cnt[maxid[i]]+=1;
		ans+=maxres[i];
	}
	int res=n/2+1;
	int anss=0;
	for(int i=1;i<=m;i++){
		int ress=ans;
		if(cnt[i]>res){
			cout<<ans<<'\n';
			return;
		}
		else{
			int resss=res-cnt[i];
			vector<int> vec;
			for(int j=1;j<=n;j++){
				if(maxid[j]!=i){
					vec.push_back(maxres[j]-a[j][i]);
				}
			}
			sort(vec.begin(),vec.end());
			for(int i=0;i<resss;i++){
				ress-=vec[i];
			}
			anss=max(anss,ress);
		}
	}
	cout<<anss<<'\n';

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