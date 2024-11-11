#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	vector<int> a(n);
	long long x=0;
	for(int i=0;i<n;i++){
		a[i]=(s[i]-'0')*(i+1);
		x+=a[i];
	}
	string ans="";
	int id=n-1;
	long long res=0;
	while(res/10+x){
		res=res/10+x;
		char ch=(res%10)+'0';
		ans=ch+ans;
		if(~id){
			x-=a[id];
			id--;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}