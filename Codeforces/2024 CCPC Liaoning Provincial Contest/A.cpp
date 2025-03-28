#include<bits/stdc++.h>

using namespace std;

void solve(){
	string str;
	getline(cin,str);
	string res="";
	set<string> se;
	for(auto ch:str){
		if(('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')){
			ch=tolower(ch);
			res+=ch;
		}
		else{
			if(res!=""){
				se.insert(res);
				res="";
			}
		}
	}
	int ans=se.size();
	int n;
	cin>>n;
	set<string> see;
	for(int i=1;i<=n;i++){
		string ss;
		cin>>ss;
		see.insert(ss);
	}
	for(auto x:see){
		if(se.count(x)) ans--;
	}
	cout<<ans<<'\n';
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
