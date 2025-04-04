#include <bits/stdc++.h>

using namespace std;

constexpr int mod=998244353;

long long qmi(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

long long inv(long long x){
	return qmi(x,mod-2);
}

void solve(){
	// cout<<7ll*inv(8)%mod<<'\n';
	vector<double> a(200);
	a[0]=1;
	a[1]=0.5;
	a[2]=1;
	a[3]=0.75;
	a[4]=0.5;
	a[5]=1;
	a[6]=0.5;
	a[7]=1;
	a[8]=0.875;
	int n;
	cin>>n;
	if(n==1){
		cout<<inv(2)<<'\n';
	}
	else if(n==3){
		cout<<3ll*inv(4)%mod<<'\n';
	}
	else if(n%5==2||n%5==0){
		cout<<1<<'\n';
	}
	else if(n%5==1||n%5==4){
		int res=(n+1)/5;
		cout<<(1-inv(qmi(2,res))+mod)%mod<<'\n';
	}
	else{
		int res=(n+1)/5+2;
		cout<<(1-inv(qmi(2,res))+mod)%mod<<'\n';
	}
	// for(int i=9;i<=108;i++){
	// 	double a1=0,a2=0,a3=0;
	// 	if(i-2>=0) a1=a[i-2];
	// 	if(i-5>=0) a2=a[i-5];
	// 	if(i-8>=0) a3=a[i-8];
	// 	a[i]=0.5*(max(a1,a2)+max(a2,a3));
	// 	cout<<i<<' '<<a[i]<<'\n';
	// }
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