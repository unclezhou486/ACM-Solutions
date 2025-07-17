#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin(),b.end());
	// for(auto x:b){
	// 	cout<<x<<' ';
	// }
	// cout<<'\n';
	if(k==1){
		cout<<"YES\n";
		return;
	}
	int x=b[k-2];
	vector<int> c;
	for(int i=0;i<n;i++){
		if(a[i]<=x){
			c.push_back(i);
		}
	}
	int l=0,r=c.size()-1;
	int res=c.size()-k+1;
	while(l<r){
		if(a[c[l]]==a[c[r]]){
			l++,r--;
		}
		else{
			if(!res){
				cout<<"NO\n";
				return;
			}
			if(a[c[l]]==x){
				l++;
				res--;
			}
			else if(a[c[r]]==x){
				r--;
				res--;
			}
			else{
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
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