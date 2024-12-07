#include <bits/stdc++.h>

using namespace std;

int a[20];
int b[20];
int c[20];
void solve(){
	int x;
	cin>>x;
	if(x==0){
		cout<<0<<'\n';
	}
	else{
		int n=0;
		int y=x;
		while(x){
			n+=1;
			a[n]=x%10;
			x/=10;
		}
		for(int i=1;i<=n;i++){
			b[i]=i;
		}
		long long ans=0;
		do{
			for(int i=1;i<=n;i++){
				c[i]=a[b[i]];
			}
			long long ress=1;
			for(int i=n;i>=1;i-=3){
				long long res=0;
				for(int j=i-2;j<=i;j++){
					res*=10;
					if(j>=1)res=res+c[j];
				}
				ress*=res;
			}
			ans=max(ans,ress);
		}while(next_permutation(b+1,b+1+n));
		cout<<ans<<'\n';
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