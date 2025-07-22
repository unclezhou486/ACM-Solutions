#include<bits/stdc++.h>

using namespace std;

long long sol(long long num){
	vector<long long> a={2,3,5,7};
	long long res=0;
	for(int i=0;i<4;i++){
		long long x=a[i];
		res+=num/x;
		for(int j=i+1;j<4;j++){
			long long y=x*a[j];
			res-=num/y;
			for(int k=j+1;k<4;k++){
				long long z=y*a[k];
				res+=num/z;
				for(int l=k+1;l<4;l++){
					long long xx=z*a[l];
					res-=num/xx;
				}
			}
		}
	}
	return res;
}

void solve(){
	long long l,r;
	cin>>l>>r;
	cout<<(r-l+1)-(sol(r)-sol(l-1))<<'\n';
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
