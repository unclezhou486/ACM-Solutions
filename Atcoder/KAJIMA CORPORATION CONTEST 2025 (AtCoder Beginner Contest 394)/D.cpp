#include<bits/stdc++.h>

using namespace std;

bool check(char x,char y){
	if((x=='['&&y==']')||(x=='('&&y==')')||(x=='<'&&y=='>')){
		return 1;
	}
	else return 0;
}

void solve(){
	string str;
	cin>>str;
	stack<int> st;
	for(auto x:str){
		if(!st.size()){
			st.push(x);
		}
		else{
			if(check(st.top(),x)){
				st.pop();
			}
			else{
				st.push(x);
			}
		}
	}
	if(st.size()){
		cout<<"No\n";
	}
	else cout<<"Yes\n";
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
