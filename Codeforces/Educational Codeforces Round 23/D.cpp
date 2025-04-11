#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10),l1(n+10),r1(n+10),l2(n+10),r2(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	stack<pair<int,int> > st1,st2;
	st1.push({0,0});
	st2.push({1e7,0});
	for(int i=1;i<=n;i++){
		while(st1.size()&&st1.top().first>=a[i]) st1.pop();
		while(st2.size()&&st2.top().first<=a[i]) st2.pop();
		l1[i]=st1.top().second+1;
		l2[i]=st2.top().second+1;
		st1.push({a[i],i});
		st2.push({a[i],i});
	}
	while(st1.size()) st1.pop();
	while(st2.size()) st2.pop();
	st1.push({0,n+1});
	st2.push({1e7,n+1});
	for(int i=n;i>=1;i--){
		while(st1.size()&&st1.top().first>a[i]) st1.pop();
		while(st2.size()&&st2.top().first<a[i]) st2.pop();
		r1[i]=st1.top().second-1;
		r2[i]=st2.top().second-1;
		st1.push({a[i],i});
		st2.push({a[i],i});
	}
	long long res1=0,res2=0;
	for(int i=1;i<=n;i++){
		res1+=1ll*(r1[i]-i+1)*(i-l1[i]+1)*a[i];
		res2+=1ll*(r2[i]-i+1)*(i-l2[i]+1)*a[i];
	}
	// cout<<res2<<' '<<res1<<'\n';
	cout<<res2-res1<<'\n';
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