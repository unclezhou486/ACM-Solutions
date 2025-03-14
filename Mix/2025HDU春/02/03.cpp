#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e6+10;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	vector<int> p(N),po(N),pop(N),cnt(n+10);
	vector<int> vis(N);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int count=0;
	for(int i=n;i>=1;i--){
		if(a[i]&&!vis[a[i]]){
			count++;
			vis[a[i]]=1;
		}
		cnt[i]=count;
	}
	vector<int> vec;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			for(auto x:vec){
				po[x]=1;
			}
			vec.clear();
		}
		else{
			p[a[i]]=1;
			if(po[a[i]]==0){
				vec.push_back(a[i]);
			}
			if(po[a[i]]&&!pop[a[i]]){
				pop[a[i]]=1;
				ans+=cnt[i+1];
			}
		}
	}
	cout<<ans<<'\n';
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