#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;


int n;

stack<char> st;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(st.empty()) st.push(ch);
		else{
			if(st.top()=='f'){
				if(ch=='c'){
					st.pop();
				}
				else{
					st.push(ch);
				}
			}
			else if(st.top()=='t'){
				if(ch=='b'){
					st.pop();
				}
				else st.push(ch);
			}
			else{
				st.push(ch);
			}
		}
	}
	cout<<st.size()<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;

}