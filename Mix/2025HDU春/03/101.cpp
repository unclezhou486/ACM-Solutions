#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int x,y;
	bool operator<(const node &a){
		// return x<a.x;
		if(x==a.x) return y<a.y;
		else return x<a.x;
	}
};


void solve(){
	int n,m;
	cin>>n>>m;
	vector<node> a(n+10),b(m+10);
	vector<int> ans(m+10);
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].x>>b[i].y;
	}
	sort(a.begin()+1,a.begin()+1+n);
	sort(b.begin()+1,b.begin()+1+m);
	int id=1;
	int maxn1=-2e9,maxn2=-2e9;
	// int x1=,x2,y1,y2;
	for(int i=1;i<=m;i++){
		while(id<=n&&a[id].x<=b[i].x){
			// if(maxn1>)
			maxn1=max(maxn1,a[id].y-a[id].x);
			maxn2=max(maxn2,-a[id].y-a[id].x);
			id+=1;
		}
		ans[i]=max(b[i].x-b[i].y+maxn1,b[i].x+b[i].y+maxn2);
	}
	id=n;
	maxn1=-2e9,maxn2=-2e9;
	for(int i=m;i>=1;i--){
		while(id>=1&&a[id].x>=b[i].x){
			maxn1=max(maxn1,a[id].x+a[id].y);
			maxn2=max(maxn2,a[id].x-a[id].y);
			id-=1;
		}
		ans[i]=max(ans[i],max(-b[i].y-b[i].x+maxn1,-b[i].x+b[i].y+maxn2));
	}
	int anss=2e9;
	for(int i=1;i<=m;i++){
		anss=min(anss,ans[i]);
	}
	cout<<anss<<'\n';
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