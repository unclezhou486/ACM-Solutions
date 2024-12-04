#include <iostream>
#include <algorithm>

using namespace std;

const int N=4e5+10;


string s;

int ne[N];
int n;
void solve(){
	cin>>s;
	n=s.size();
	s='#'+s;
	ne[1]=0;
	for(int i=2;i<=n;i++){
		int j=ne[i-1];
		while(j>0&&s[i]!=s[j+1]) j=ne[j];
		if(s[i]==s[j+1]) j++;
		ne[i]=j;
	}
	if(ne[n]<=n/2){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		for(int i=1;i<=ne[n];i++){
			cout<<s[i];
		}
		cout<<'\n';
	}
	// cout<<ne[n]<<'\n';
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