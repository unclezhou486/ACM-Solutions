#include <bits/stdc++.h>

using namespace std;

/*1 i n

[1,i-1] > a[i] + [i+1,n] < a[i] 
== 
( [1,i-1] > 2n-a[i] ) +( [i+1,n] < 2n-a[i] )

*/

void solve() {
	int n;
	cin>>n;
	vector<int> a(n+10);
	vector<int> b(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int res1=0,res2=0;
		for(int j=1;j<i;j++){
			res1+=(a[j]>a[i]);
		}
		for(int j=i+1;j<=n;j++){
			res2+=(a[j]>a[i]);
		}
		if(res1>res2){
			b[i]=2*n-a[i];
		}
		else{
			b[i]=a[i];
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ans+=(b[j]>b[i]);
		}
	}
	cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}