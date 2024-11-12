#include <bits/stdc++.h>

using namespace std;

long long xorpre(long long x){
	if(x<0) return 0;
	if(x%4==1) return 1;
	else if(x%4==2) return x+1;
	else if(x%4==3) return 0;
	else return x;
}

void solve(){
	long long l,r,i,k;
	cin>>l>>r>>i>>k;
	long long res=xorpre(r)^xorpre(l-1);
	long long bit=(1<<i);
	long long x=xorpre((r-k)>>i)^xorpre(((l-k+bit-1)/bit)-1);
	x<<=i;
	x^=k*((((r-k)>>i)-((l-k-1)>>i))&1);//avoid to be < 0
	cout<<(res^x)<<'\n';
}

int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}