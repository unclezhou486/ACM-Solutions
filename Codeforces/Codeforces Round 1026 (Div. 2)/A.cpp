#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+1+n);
	int min1=-1,min2=-1,max1=-1,max2=-1;
	for(int i=1;i<=n;i++){
		if(a[i]%2==0){
			if(min2==-1){
				min2=i;
			}
			max2=i;
		}
		else{
			if(min1==-1){
				min1=i;
			}
			max1=i;
		}
	}
	// cout<<min1<<' '<<max1<<' '<<min2<<' '<<max2<<'\n';
	int ans=min(min1-1+(n-max1),min2-1+(n-max2));
	cout<<ans<<'\n';
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
