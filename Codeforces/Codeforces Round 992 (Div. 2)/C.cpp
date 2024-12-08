#include <bits/stdc++.h>
#define int long long
using namespace std;


void dabiao(){
	int a[100];
	int n;
	// cin>>n;
	n=8;
	vector<pair<int,vector<int>>> vec;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	do{
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				int res=1e9;
				for(int i=l;i<=r;i++){
					res=min(res,a[i]);
				}
				ans+=res;
			}
		}
		vector<int> vecc;
		for(int i=1;i<=n;i++){
			vecc.push_back(a[i]);
		}
		vec.push_back({-ans,vecc});
	}while(next_permutation(a+1,a+1+n));
	sort(vec.begin(),vec.end());
	int ansx=-1;
	int cnt=1;
	for(auto [x,y]:vec){
		if(ansx==-1) ansx=x;
		else{
			if(x!=ansx){
				cout<<cnt<<'\n';
				return;
			} 
		}
		cnt++;
		for(auto xx:y){
			cout<<xx<<' ';
		}
		cout<<'\n';
	}

}


void solve(){
	int n,k;
	cin>>n>>k;
	if(n<=60){
		if((1ll<<(n-1))<k){
			cout<<-1<<'\n';
			return;
		}
	}
	vector<int> ans(n+10);
	int h=1,t=n;
	int nn=n-2;
	for(int i=1;i<=n;i++){
		if(nn>60){
			ans[h++]=i;
		}
		else{
			if((1ll<<nn)<k){
				k-=(1ll<<nn);
				ans[t--]=i;
			}
			else{
				ans[h++]=i;
			}
		}
		nn--;
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