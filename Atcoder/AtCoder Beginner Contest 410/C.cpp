#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n+10);
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	int id=0;
	while(q--){
		int op,p,x;
		cin>>op;
		if(op==1){
			cin>>p>>x;
			p-=1;
			a[(id+p)%n]=x;
		}
		else if(op==2){
			cin>>p;
			p-=1;
			cout<<a[(id+p)%n]<<'\n';
		}
		else{
			cin>>x;
			id=(id+x)%n;
		}
	}
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
