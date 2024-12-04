#include <bits/stdc++.h>

using namespace std;

const int N=4e5+10;

int n,k,q;
int a[N];
int cnt[N],res[N];
int ans[N];


void solve(){
	// cout<<"CCF\n";
	cin>>n>>k>>q;
	int ress=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]-i+n;
		// cout<<a[i]<<" \n"[i==n];
	}
	for(int i=1;i<=k;i++){
		cnt[a[i]]+=1;
		res[cnt[a[i]]]+=1;
		ress=max(ress,cnt[a[i]]);
	}
	ans[1]=ress;
	for(int i=k+1;i<=n;i++){
		// for(int j=1;j<=2*n;j++){
		// 	cout<<cnt[j]<<" \n"[j==2*n];
		// }
		// for(int j=1;j<=2*n;j++){
		// 	cout<<res[j]<<" \n"[j==2*n];
		// }
		int l=i-k+1;
		res[cnt[a[l-1]]]-=1;
		if(!res[cnt[a[l-1]]]&&ress==cnt[a[l-1]]) ress-=1;
		cnt[a[l-1]]-=1;
		cnt[a[i]]+=1;
		res[cnt[a[i]]]+=1;
		ress=max(ress,cnt[a[i]]);
		ans[l]=ress;
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<k-ans[l]<<'\n';
	}
	for(int i=0;i<=2*n;i++){
		cnt[i]=res[i]=0;
	}
	// cout<<"ATF\n";
	// for(int i=0;i<=20;i++){
	// 	cout<<cnt[i]<<" \n"[i==20];
	// }
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
/*

8 1 4
5 3 2 5 4 5 3 6 5 5
8 8
3 3
1 1

*/