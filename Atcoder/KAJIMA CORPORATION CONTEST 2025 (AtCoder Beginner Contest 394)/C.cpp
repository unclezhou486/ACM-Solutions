#include<bits/stdc++.h>

using namespace std;

void solve(){
	string str;
	cin>>str;
	int n=str.size();
	for(int i=n-1;i>0;i--){
		if(str[i]=='A'&&str[i-1]=='W'){
			int j=i;
			while(j>0&&str[j-1]=='W'){
				j-=1;
			}
			str[j]='A';
			for(int k=j+1;k<=i;k++){
				str[k]='C';
			}
			i=j;
		}
	}
	cout<<str;
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
