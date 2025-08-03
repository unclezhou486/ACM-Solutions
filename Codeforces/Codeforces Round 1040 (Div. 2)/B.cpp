#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n,s;
	cin>>n>>s;
	vector<int> a(n+1);
	int sum=0;
	int cnt0=0,cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]==0){
			cnt0++;
		}
		else if(a[i]==1){
			cnt1++;
		}
		else{
			cnt2++;
		}
	}
	if(sum==s){
		cout<<-1<<'\n';
	}
	else if(sum>s){
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" \n"[i==n];
		}
	}
	else{
		if(s-sum==1){
			for(int i=1;i<=cnt0;i++){
				cout<<0<<' ';
			}
			for(int i=1;i<=cnt2;i++){
				cout<<2<<' ';
			}
			for(int i=1;i<=cnt1;i++){
				cout<<1<<' ';
			}
			cout<<'\n';
		}
		else{
			cout<<-1<<'\n';
		}
	}
}

// 2 3

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