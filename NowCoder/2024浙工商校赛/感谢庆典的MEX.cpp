#pragma GCC O(2)
#pragma GCC O(3)
#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e5+10;

int n;
long long m;
long long a[N];

bool check(int x){
	multiset<long long> se;
	for(int i=1;i<=n;i++){
		se.insert(a[i]);
	}
	while(x>=0){
		if(se.find(x)!=se.end()){
			se.extract(x);
			x--;
			continue;
		}
		vector<long long> vec;
		auto it=se.upper_bound(x);
		auto itt=it;
		for(;itt!=se.end();itt++){
			long long  y=(*itt);
			while(y>x){
				y/=m;
			}
			vec.push_back(y);
			if(y==x){
				itt++;
				break;
			} 
		}
		se.erase(it,itt);
		for(auto x:vec) se.insert(x);
		if(se.find(x)==se.end()){
			return 0;
		}
		else{
			se.extract(x);
			x--;
		}
	}
	return 1;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(ans==a[i]){
				ans+=1;
			}
		}
		cout<<ans<<'\n';
		return;
	}
	int l=0,r=n;
	if(n>10&&check((n-10))) l=n-10;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else{
			for(int i=1;i<=n;i++){
				while(a[i]>=mid){
					a[i]/=m;
				}
			}
			r=mid-1;
		} 
	}
	cout<<l+1<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	solve();
	return 0;
}