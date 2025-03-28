#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	stack<unsigned long long > st;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s=="push"){
			unsigned long long x;
			cin>>x;
			st.push(x);
		}
		else if(s=="pop"){
			if(st.empty()){
				cout<<"Empty\n";
			}
			else{
				st.pop();
			}
		}
		else if(s=="query"){
			if(st.empty()){
				cout<<"Anguei!\n";
			}
			else{
				cout<<st.top()<<'\n';
			}
		}
		else if(s=="size"){
			cout<<st.size()<<'\n';
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
