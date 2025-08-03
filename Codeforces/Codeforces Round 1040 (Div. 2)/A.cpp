#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(!x) x=1;
		ans+=x;
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