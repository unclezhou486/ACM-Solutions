#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int a[N];

void solve(){
	int n;
	cin>>n;
	int aa,bb;
	aa=bb=0;
	int res=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];if(a[i]==1) aa++;else bb++;
	}
	int t=n;
	for(int i=n;i>=1;i--){
		if(a[t]==1){
			if(bb){
				if(a[i]==2){
					res++;
					t=i-1;
				}
			}
			else{
				res+=aa;
				break;
			}
		}
		else{
			if(aa){
				if(a[i]==1){
					res++;
					t=i-1;
				}
			}
			else{
				res+=bb;
				break;
			}
		} 
		if(a[i]==1)aa--;
		else bb--;
	}
	cout<<res<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 