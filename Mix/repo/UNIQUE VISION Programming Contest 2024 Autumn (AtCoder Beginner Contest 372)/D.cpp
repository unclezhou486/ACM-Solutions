#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int N=2e5+10;

int n;

int h[N];
int ans[N];

stack<int> st;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=n;i>=1;i--){
		ans[i]=st.size();
		while(st.size()&&st.top()<h[i]) st.pop();
		st.push(h[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}