#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n-1;i++){
		if(s[i]>s[i+1]){
			// int r=n-1;
			int l=i,r=n;
			for(int j=i+2;j<n;j++){
				if(s[j]>s[i]){
					r=j;
					break;
				}
			}
			// cout<<l<<' '<<r<<'\n';
			for(int j=0;j<l;j++){
				cout<<s[j];
			}
			for(int j=l+1;j<r;j++){
				cout<<s[j];
			}
			cout<<s[l];
			for(int j=r;j<n;j++){
				cout<<s[j];
			}
			cout<<'\n';
			return;
		}
	}
	cout<<s<<'\n';
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