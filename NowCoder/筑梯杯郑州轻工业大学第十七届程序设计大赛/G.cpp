#include <bits/stdc++.h>

using namespace std;

struct node{
	int x,id;
	int a,b;
};

bool cmp(node a,node b){
	return a.a>b.a;
}

void solve(){
	int n;
	cin>>n;
	vector<node> a(n+10);
	vector<int> ans(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
	}
	sort(a.begin()+1,a.begin()+1+n,cmp);
	int res=n;
	for(int i=1;i<=n;i++){
		res--;
		int x=a[i].b;
		ans[a[i].id]=max(0,2*x-res);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
	}
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