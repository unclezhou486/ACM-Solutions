#include <bits/stdc++.h>

using namespace std;

void solve(){
	int p,n,k;
	cin>>p>>n>>k;
	vector<int> a,b;
	for(int i=1;i<=n;i++){
		int t,p;
		cin>>t>>p;
		if(t==0){
			a.push_back(p);
		}
		else{
			b.push_back(p);
		}
	}
	sort(a.begin(),a.end());
	// reverse(a.b)
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	int nn=a.size();
	int mm=b.size();
	vector<double> aa(nn+10);
	vector<long long> bb(mm+10);
	aa[0]=1;
	for(int i=1;i<=nn;i++){
		aa[i]=aa[i-1]*(1.0*a[i-1]/10);
	}
	for(int i=1;i<=mm;i++){
		bb[i]=bb[i-1]+b[i-1];
	}
	double ans=p;
	for(int i=0;i<=min(k,nn);i++){
		ans=min(ans,p*aa[i]-bb[k-i]);
	}
	ans=max(ans,0.0);
	cout<<fixed<<setprecision(2)<<ans<<'\n';
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