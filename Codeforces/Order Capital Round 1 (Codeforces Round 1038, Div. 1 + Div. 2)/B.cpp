#include<bits/stdc++.h>

using namespace std;

struct node{
	int a,b,c,d;
};

void solve(){
	int n;
	cin>>n;
	vector<node> vec(n);
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>vec[i].a>>vec[i].b>>vec[i].c>>vec[i].d;
		ans+=max(vec[i].a-vec[i].c,0);
		if(vec[i].b>vec[i].d){
			ans+=min(vec[i].a,vec[i].c);
			ans+=vec[i].b-vec[i].d;
		}
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
