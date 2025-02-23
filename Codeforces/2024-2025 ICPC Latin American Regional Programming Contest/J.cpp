#include <bits/stdc++.h>

using namespace std;

void solve(){
	double k;
	int n;
	cin>>k>>n;
	vector<pair<int,int> > a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a.begin()+1,a.begin()+1+n);
	double last=0;
	double ans=0;
	for(int i=1;i<=n;i++){
		double len=a[i].second/tan(k/360*(2*acos(-1) ) ) ;
		double res=a[i].first+len;
		if(last<a[i].first){
			ans+=len;
			last=res;
		}
		else{
			ans+=max(0.0,res-last);
			last=max(last,res);
		}
	}
	cout<<fixed<<setprecision(6)<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}