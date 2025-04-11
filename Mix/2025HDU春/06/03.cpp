#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10),b(n+10);
	int idla=0;
	int lac=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	long long ans=0;
	long long res=0;
	for(int i=1;i<=n;i++){
		if(a[i]+b[i]==lac){
			res+=a[i];
		}
		else{
			res=a[i];
			lac=a[i]+b[i];
			idla=i-1;
		}
		ans=max(ans,res*(i-idla));
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