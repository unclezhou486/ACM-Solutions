#include<bits/stdc++.h>
#define int long long
using namespace std;

long long dis(long long x,long long y){
	x=abs(x),y=abs(y);
	if(x>1e9||y>1e9){
		return 2e18;
	}
	return x*x+y*y;
}

void solve(){
	int n;
	long long d;
	cin>>n>>d;
	long long dd=d*d;
	long long sumx=0,sumy=0;
	vector<long long> x(n+10),y(n+10);
	// bool flag=false;
	int ans=-1;
	for(int i=1;i<=n;i++){
		long long a,b;
		cin>>a>>b;
		x[i]=x[i-1]+a;
		y[i]=y[i-1]+b;
		sumx+=a;
		sumy+=b;
		if(dis(x[i],y[i])>=dd&&ans==-1){
			// cout<<i<<'\n';
			// return;
			// flag=true;
			ans=i;
		}
	}
	if(ans!=-1){
		cout<<ans<<'\n';
		return;
	}
	auto check = [&] (int r) -> bool{
		for(int i=0;i<n;i++){
			if(dis(x[i]+r*sumx,y[i]+r*sumy)>=dd){
				return 1;
			}
		}
		return 0;
	};
	int l=1,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	for(int i=0;i<n;i++){
		if(dis(x[i]+l*sumx,y[i]+l*sumy)>=dd){
			cout<<1ll*i+1ll*l*n<<'\n';
			return;
		}
	}
	cout<<"infinity\n";
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
