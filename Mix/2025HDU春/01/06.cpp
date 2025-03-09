#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	long long a=0,b=0,c=0;
	cin>>n;
	set<long long> se,se1;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		se1.clear();
		long long x;
		if((c-b)%a==0){
			x=(c-b)/a;
			if(x>=0)se1.insert(x);
			x=(b-c)/a;
			if(x>=0)se1.insert(x);
		}
		if((c-a)%b==0){
			x=(c-a)/b;
			if(x>=0)se1.insert(x);

			x=(a-c)/b;
			if(x>=0)se1.insert(x);
		}
		if((b-a)%c==0){
			x=(b-a)/c;
			if(x>=0)se1.insert(x);
			x=(a-b)/c;
			if(x>=0)se1.insert(x);
		}
		if(se.empty()){
			for(auto x:se1){
				se.insert(x);
			}
		}
		else{
			vector<int> vec;
			for(auto x:se){
				if(!se1.count(x)){
					vec.push_back(x);
				}
			}
			for(auto x:vec){
				se.erase(x);
			}
		}
	}
	cout<<*se.begin()<<'\n';
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