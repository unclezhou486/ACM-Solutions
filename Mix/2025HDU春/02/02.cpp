#include <bits/stdc++.h>

using namespace std;

string a[10]={"jia","yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};

string b[12]={"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};

void solve(){
	string str;
	cin>>str;
	int x=0,y=0;
	for(int i=1984;i<=2043;i++){
		string res=a[x]+b[y];
		if(res==str){
			cout<<i<<'\n';
			return;
		}
		x+=1;
		y+=1;
		if(y==12){
			y=0;
		}
		if(x==10){
			x=0;
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