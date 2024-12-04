#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n;

int a[N];

int idl[N],idr[N];

int b[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!idl[a[i]]) idl[a[i]]=i;
		idr[a[i]]=max(idr[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		if(idl[i]==idr[i]) continue;
		b[idl[i]+1]+=1;
		b[idr[i]]-=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		cout<<b[i]<<" \n"[i==n];
		if(b[i]) ans+=1;
	}
	cout<<ans<<'\n';
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