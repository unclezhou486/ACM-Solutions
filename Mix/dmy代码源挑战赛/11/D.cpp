#include <bits/stdc++.h>

using namespace std;

void solve(){
	
	set<long long> se;

	vector<string> vec1,vec2;
	queue<string> qu;
	for(int i=1;i<=9;i++){
		qu.push(to_string(i));
		vec1.push_back(to_string(i));
	}
	while(qu.size()){
		string x=qu.front();
		qu.pop();
		int res=x.back()-'0';
		for(int i=0;i<res;i++){
			string res=x+to_string(i);
			qu.push(res);
			vec1.push_back(res);
		}
	}
	vec2=vec1;
	for(auto &x:vec2){
		reverse(x.begin(),x.end());
	}
	for(auto x:vec1){
		for(auto y:vec2){
			string res=x+y;
			if(x[0]==y.back()&&x.back()<y[0]&&res.size()<=18){
				se.insert(stoll(res));
			}
		}
	}
	vector<long long> vec;
	for(auto x:se){
		vec.push_back(x);
	}
	// cout<<se.size()<<'\n';
	int q;
	cin>>q;
	while(q--){
		long long l,r;
		cin>>l>>r;
		auto it=lower_bound(vec.begin(),vec.end(),l);
		auto itt=upper_bound(vec.begin(),vec.end(),r);
		itt--;
		cout<<itt-it+1<<'\n';
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