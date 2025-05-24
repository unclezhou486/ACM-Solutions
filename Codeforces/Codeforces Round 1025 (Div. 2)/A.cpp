#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i>1){
			if(a[i]==0&&a[i-1]==0){
				// cout<<i<<' '<<i-1<<'\n';
				cout<<"YES\n";
				return;
			}
		}
		if(a[i]){
			cnt++;
		}		
	}
	// cout<<cnt<<'\n';
	// cout<<n<<'\n';
	if(cnt==n){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
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
