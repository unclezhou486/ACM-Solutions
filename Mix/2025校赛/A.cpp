#include<bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<"1\n1\n";
		return;
	}
	int n=s.size();
	int cnt0=0,cnt1=0;
	for(auto ch:s){
		if(ch=='0') cnt0+=1;
		else if(ch=='1') cnt1+=1;
	}
	if(s[0]=='0'&&s[n-1]=='1'){
		cout<<"0\n\n";
		return;
	}
	int l=cnt0+1,r=n-cnt1;
	if(s[0]=='1') r+=1;
	if(s[n-1]=='0') l-=1;
	cout<<(r-l+1)<<'\n';
	for(int i=l;i<=r;i++){
		cout<<i<<" \n"[i==r];
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
