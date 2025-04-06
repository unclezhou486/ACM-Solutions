#include <bits/stdc++.h>

using namespace std;

int main(){
	srand(clock());
	int n,m,k,p;
	// n=rand()%100000+2;
	// m=rand()%100000+1;
	n=100000;
	m=200000;
	if(m<n) swap(n,m);
	k=10,p=rand()%n+1;
	cout<<n<<' '<<m<<' '<<k<<' '<<p<<'\n';
	for(int i=1;i<=m;i++){
		int u,v,t;
		u=rand()%n+1;
		v=rand()%n+1;
		while(u==v) v=rand()%n+1;
		t=rand();
		cout<<u<<' '<<v<<' '<<t<<'\n';
	}
	for(int i=1;i<=k;i++){
		int s,t;
		s=rand()%n+1,t=rand()%n+1;
		while(t==s) t=rand()%n+1;
		cout<<s<<' '<<t<<'\n';
	}
	return 0;
}