#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	set<int> se;
	bool flag=false;
	for(int i=0;i<n;i++){
		cin>>a[i];
		se.insert(a[i]);
	}
	a[n]=a[0];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) flag=true;
	}
	if(se.size()==1){
		cout<<1<<'\n';
		for(int i=0;i<n;i++){
			cout<<1<<" \n"[i==n-1];
		}
	}
	else if(n%2==0){
		cout<<2<<'\n';
		int x=1;
		for(int i=0;i<n;i++){
			cout<<x<<" \n"[i==n-1];
			x=(x%2)+1;
		}
	}
	else if(flag==false){
		cout<<3<<'\n';
		int x=1;
		for(int i=0;i<n-1;i++){
			cout<<x<<' ';
			x=x%2+1;
		}
		cout<<3<<'\n';
	}
	else{
		cout<<2<<'\n';
		bool fl=false;
		int x=1;
		for(int i=0;i<n;i++){
			if(i&&!fl&&a[i]==a[i-1]){
				fl=true;
				// cout<<(i-1)%2
				// x^=1;
				x=x%2+1;
				cout<<x<<" \n"[i==n-1];
			}
			else{
				cout<<x<<" \n"[i==n-1];
			}
			// x^=1;
			x=x%2+1;
		}
	}

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


//1011

//1010


//a4!=b4

//2steps

//a1 a2 a3 a4

//a4^1 a3^1 a2^1 a1^1

//a2 a3 a4 a1^1

//2steps

//a1 a2 a3 a4

//a1^1 a2 a3 a4

//a4^1 a3^1 a2^1 a1
