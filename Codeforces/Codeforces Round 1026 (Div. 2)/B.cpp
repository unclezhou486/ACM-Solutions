#include<bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	stack<int> st; 
	for(int i=0;i<s.size()-1;i++){
		char x=s[i];
		if(x=='('){
			st.push(i);
		}
		else{
			st.pop();
		}
	}
	if(st.top()==0){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
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
