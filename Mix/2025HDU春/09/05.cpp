#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s,t;
	cin>>s>>t;
	vector<string> vec1,vec2;
	vec1={"a","i","u","o","e","ya","yu","yo"};
	vec2={"","k","g","s","z","t","d","n","h","b","p","m","r","w"};
	set<string> se;
	for(auto a:vec2){
		for(auto b:vec1){
			if((a=="d"&&!(b=="a"||b=="e"||b=="o"))||(a=="w"&&b!="a")) continue;
			se.insert(a+b);
		}
	}
	se.insert("nn");
	auto check = [&](string str) -> int{
		int res=0;
		int n=str.size();
		for(int i=0;i<n;i++){
			string ress="";
			ress+=str[i];
			if(se.count(ress)){
				res+=1;
				continue;
			}
			if(i+1<n){
				ress+=str[i+1];
				if(se.count(ress)){
					res+=1;
					i+=1;
					continue;
				}
			}
			if(i+2<n){
				ress+=str[i+2];
				if(se.count(ress)){
					res+=1;
					i+=2;
					continue;
				}
			}
			res+=1;
		}
		return res;
	};
	cout<<check(s)<<' '<<check(t)<<'\n';

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