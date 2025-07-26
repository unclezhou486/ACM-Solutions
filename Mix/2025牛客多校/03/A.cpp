#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> f(n+10);
	vector<vector<int> > a(n+10,vector<int>(n+10) );
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	for(int i=1;i<=n;i++){
		deque<int> vec;
		for(int j=0;j<f[i];j++){
			vec.push_back(j);
		}
		for(int j=1;j < f[i];j++){
			if(vec.front()==f[j]){
				a[i][j]=a[j][i]=vec.back();
				vec.pop_back();
			}
			else{
				a[i][j]=a[j][i]=vec.front();
				vec.pop_front();
			}
		}
		a[i][i]=vec.back();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" \n"[j==n];
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