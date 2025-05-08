#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void change(int &q,int &p,int qq,int pp){
	int gd=p/gcd(p,pp)*pp;
	q=q*(gd/p)+qq*(gd/pp);
	p=gd;
    int gdd=gcd(q,p);
    q/=gdd,p/=gdd;
}

void solve(){
	int n1,n2;
	cin>>n1>>n2;
	// set<double> se;
	set<pair<int,int> > se;
	// double res=0;
	int resq=0,resp=1;
	for(int i=1;i<=n1;i++){
		int p,q;
		cin>>p>>q;
		se.insert({resq,resp});
		change(resq,resp,p,q);
	}	
	int ans=0;
	// res=0;
	resq=0,resp=1;
	for(int i=1;i<=n2;i++){
		int p,q;
		cin>>p>>q;
		if(se.count({resq,resp})) ans+=1;
		// res+=(1.0*p/q);
		change(resq,resp,p,q);
	}
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