#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<char> a(n+10),b(n+10);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int ans1=0,ans2=0;
	vector<int> vec(2*n+10);
	int idx=0;
	auto check = [&] (char ch,int &ans) -> void{
		if('0'<=ch&&ch<='9'){
			int lock=-1;
			int has=-1;
			for(int i=0;i<idx;i++){
				if(vec[i]==ch){
					has=1;
				}
				if(vec[i]=='Q'&&)
			}
		}
	};
	for(int i=1;i<=n;i++){
		check(a[i],ans1);
		check(b[i],ans2);
	}
	cout<<ans1<<' '<<ans2<<'\n';
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