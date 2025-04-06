#include <bits/stdc++.h>

using namespace std;

// double qmi(double a,int b){
// 	double res=1;
// 	while(b){
// 		if(b&1) res=res*a;
// 		a=a*a;
// 		b>>=1;
// 	}
// 	return res;
// }

void solve(){
	double a,b,n;
	cin>>a>>b>>n;
	double ans=0;
    double an=pow(a,n);
    int nn=1000000;
    double j=a/nn;
    double ress=0;
    for(int i=1;i<=nn;i++){
    	double res=b/a;
    	double xn=pow(ress,n);
    	res*=pow(an-xn,1.0/n);
    	ans+=res*j;
    	ress+=j;
    }
	// for(double j=0;j<=a;j+=0.000001){
	// 	double res=b/a;
    //     double xn=pow(j,n);
    //     res*=pow(an-xn,1.0/n);
    //     ans+=res*0.000001;
	// }
	cout<<fixed<<setprecision(6)<<ans*4<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}