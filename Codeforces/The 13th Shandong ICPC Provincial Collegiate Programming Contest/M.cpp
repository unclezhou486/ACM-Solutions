#include <bits/stdc++.h>

using namespace std;

struct node{
	long long x,y;
	node operator- (node &a){
		return (node){x-a.x,y-a.y};
	};
};

long long det(node a,node b){
	return abs(a.x*b.y-a.y*b.x);
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<node> a(2*n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i+n]=a[i];
	}
	long long res=0;
	for(int i=2;i<=k+1;i++){
		res+=det(a[i-1]-a[k+1],a[i]-a[k+1]);
	}
	long long ans=0;
	int idj=k+2;
	for(int i=1;i<=n;i++){
		int idi=i;
		int idk=i+k;
		while(idj+1<=i+n&&det(a[idi]-a[idk],a[idj]-a[idk])<=det(a[idk]-a[idi],a[idj+1]-a[idk])){
			idj+=1;
		}
		long long ress=det(a[idi]-a[idk],a[idj]-a[idk]);
		ans=max(ans,res+ress);
		res-=det(a[idk]-a[idi],a[idi+1]-a[idi]);
		res+=det(a[idk]-a[idi+1],a[idk+1]-a[idi+1]);
	}
	long double anss=1.0*ans/2;
	cout<<fixed<<setprecision(10)<<anss<<'\n';
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