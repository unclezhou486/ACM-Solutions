#include <bits/stdc++.h>

using namespace std;


void solve(){
	string s,t;
	cin>>s>>t;
	int n=s.size();
	s=s;
	t=t;
	vector<int> vec1,vec2;
	for(int i=0;i<n;i++){
		if(s[i]<t[i]){
			vec1.push_back(i);
		}
		else if(s[i]>t[i]){
			vec2.push_back(i);
		}
	}
	cout<<vec1.size()+vec2.size()<<'\n';
	for(auto x:vec2){
		s[x]=t[x];
		cout<<s<<"\n";
	}
	reverse(vec1.begin(),vec1.end());
	for(auto x:vec1){
		s[x]=t[x];
		cout<<s<<"\n";
	}
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