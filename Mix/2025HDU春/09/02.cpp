#include <bits/stdc++.h>

using namespace std;

//2 2 -3 2
void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10),b(n+10);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	vector<int> s;
	s.push_back(2e9);
	for(int i=2;i<=n;i++){
		s.push_back(b[i]);
		s.push_back(2e9);
	}
	int m=s.size();
	vector<int> d1(m);
	for(int i=0,l=0,r=-1;i<m;i++){
		int k=(i>r)? 1: min(d1[l+r-i],r-i+1);
		while(0<=i-k&& i+k<m &&s[i-k]==s[i+k]){
			k++;
		}
		d1[i]=k--;
		if(i+k>r){
			l=i-k;
			r=i+k;
		}
	}
	// for(int i=0;i<m;i++){
		// cout<<s[i]<<' ';
	// }
	// cout<<'\n';
	long long ans=0;
	for(int i=0;i<m;i++){
		ans+=d1[i]/2;
		// cout<<d1[i]-1<<' ';
	}
	cout<<ans+n<<'\n';
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