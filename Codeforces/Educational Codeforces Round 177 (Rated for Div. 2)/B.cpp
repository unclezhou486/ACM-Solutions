#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long n,k,x;
	cin>>n>>k>>x;
	vector<long long> b(n+10);
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		sum+=b[i];
	}
	long long y=((x-1)/sum);
	if(y+1>k){
		cout<<0<<'\n';
		return;
	}
	long long ans=(k-y-1)*n;
	long long res=y*sum;
	// cout<<"Y:"<<y<<'\n';
	// cout<<"ans:"<<ans<<'\n';
	for(int i=n;i>=1;i--){
		if(res+b[i]>=x){
			ans+=1;
		}
		res+=b[i];
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
