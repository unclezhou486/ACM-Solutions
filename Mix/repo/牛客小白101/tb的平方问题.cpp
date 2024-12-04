#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;


int n,q;

int a[N],pre[N];

long long b[N];

bool check(int x){
	return( (int)sqrt(x)*(int)sqrt(x))==x;
}

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int res=pre[i]-pre[j-1];
			if(check(res)){
				// cout<<j<<' '<<i<<' '<<pre[i]-pre[j-1]<<"\n";
				b[j]+=1;
				b[i+1]-=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+b[i];
		// cout<<b[i]<<" \n"[i==n];
	}
	while(q--){
		int x;
		cin>>x;
		cout<<b[x]<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;

}