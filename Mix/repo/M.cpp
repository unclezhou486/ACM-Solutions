#include <bits/stdc++.h>

using namespace std;

// map<pair<>
set<pair<int,int> > se;

void change(int &x){
	int a[30];
	int xx=x;
	for(int i=0;i<=20;i++){
		a[i]=xx%2;
		xx/=2;
	}
	for(int i=0;i<=20;i++){
		int res=0;
		a[i]^=1;
		for(int j=20;j>=0;j--){
			res*=2;
			res+=a[j];
		}
		int xx=x,yy=res;
		if(xx>yy) swap(xx,yy);
		if(!se.count({xx,yy})){
			se.insert({xx,yy});
			x=res;
			return;
		}
		a[i]^=1;
	}
}

void print(int x){
	string res="";
	for(int i=0;i<=4;i++){
		res=(char)(x%2+'0')+res;
		x/=2;
	}
	cout<<res<<'\n';
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int s=0;
	for(int i=1;i<=20;i++){
		print(s);
		// cout<<s<<'\n';
		change(s);
	}
}