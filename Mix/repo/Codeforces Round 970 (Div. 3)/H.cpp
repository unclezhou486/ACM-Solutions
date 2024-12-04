#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=2e5+10;

int n,q;

int a[N],pre[N];
int ans[N];

bool check(int k,int x){
	int res=0;
	for(int i=0;i<=n;i+=x){
		res+=pre[i+k];
		if(i>0) res-=pre[i-1];
	}
	return res>=n/2+1;
}

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[a[i]]+=1;
	}
	for(int i=1;i<=2*n;i++){
		// cout<<pre[i]<<" \n"[i==2*n];
		pre[i]+=pre[i-1];
	}
	for(int x=1;x<=n;x++){
		int l=0,r=x-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,x)) r=mid;
			else l=mid+1;
		}
		ans[x]=l;
	}
	for(int i=1;i<=q;i++){
		int x;
		cin>>x;
		cout<<ans[x]<<" \n"[i==q];
	}
	for(int i=0;i<=2*n;i++) pre[i]=0;
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