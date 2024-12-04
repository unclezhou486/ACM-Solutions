#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N=2e5+10;

int n,q;
long long sum;
long long a[N];
long long s[N];
// 1 2 3 4 5 6 7 8 9
long long pre(long long l,long long r){
	long long sum=0;
	long long ll=(l-1)/n;
	ll=(l-ll*n+ll)%n;
	if(!ll) ll=n;
	long long rr=(r-1)/n;
	rr=(r-rr*n+rr)%n;
	if(!rr) rr=n;
	if(rr<ll){
		sum=s[n]-s[ll-1]+s[rr];
	}
	else{
		sum=s[rr]-s[ll-1];		
	}
	// cout<<ll<<' '<<rr<<' '<<sum<<'\n';
	return sum;
}
void solve(){
	cin>>n>>q;
	sum=0;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i],s[i]=s[i-1]+a[i];
	while(q--){
		long long l,r;
		cin>>l>>r;
		long long ll=(((l-1)/n)+1);
		long long rr=(r-1)/n;
		long long ans=0;
		if(ll<=rr){
			long long res=(rr-ll)*sum;
			ans+=res;
			ans+=pre(l,ll*n);
			ans+=pre(rr*n+1,r);
		}
		else{
			ans+=pre(l,r);
		}
		cout<<ans<<'\n';
	}
}

//l ll rr r
//rr l r ll
//

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