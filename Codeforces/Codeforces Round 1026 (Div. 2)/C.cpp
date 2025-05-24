#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10),l(n+10),r(n+10),L(n+10),R(n+10);
	vector<int> s(n+10);
	int res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=-1){
			res+=a[i];
		}
		s[i]=res;
	}
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=n;i++){
		L[i]=max(l[i],L[i-1]);
	}
	R[n+1]=n+1;
	for(int i=n;i>=1;i--){
		R[i]=min(r[i],R[i+1]);
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<L[i]<<' '<<R[i]<<'\n';
	// }
	for(int i=1;i<=n;i++){
		if(s[i]>R[i]){
			cout<<-1<<'\n';
			return;
		}
	}
	stack<int> st;
	res=0;
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			st.push(i);
		}
		else{
			res+=a[i];
		}
		while(res<L[i]){
			if(st.size()){
				a[st.top()]=1;
				st.pop();
				res+=1;
			}
			else{
				cout<<-1<<'\n';
				return;
			}
		}
	}
	res=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			res+=a[i];
		}
		if(res>R[i]){
			cout<<-1<<'\n';
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1) a[i]=0;
		cout<<a[i]<<" \n"[i==n];
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
