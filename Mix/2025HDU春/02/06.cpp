#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>,int> ma;//1 bai 

int sol(int a,int b){
	if(ma.count({a,b})) return ma[{a,b}];
	for(int i=1;i<=min(3,a);i++){
		if(sol(a-i,b)==1){
			ma[{a,b}]=-1;
			return -1;
		}
	}
	if(b){
		if(sol(a+1,b-1)==1){
			ma[{a,b}]=-1;
			return -1;
		}
		if(sol(a,b-1)==1){
			return ma[{a,b}]=-1;
		}
		if(a){
			if(sol(a-1,b-1)==1){
				return ma[{a,b}]=-1;
			}
		}
	}
	if(b>1){
		if(sol(a+1,b-2)==1){
			return ma[{a,b}]=-1;
		}
	}
	return ma[{a,b}]=1;
}

void solve(){
	int r,b,m;
	cin>>r>>b>>m;
	if((r%4==2&&b%2==1)||(r%4==0&&b%2==0)){
		cout<<"Bob\n";
	}
	else{
		cout<<"Alice\n";
	}
}

void biao(){
	ma[{0,0}]=1;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			int res;
			if(sol(i,j)==-1) res=1;
			else res=0;
			cout<<res<<" \n"[j==10];
		}
	}
}

int main(){
	// biao();
	// return 0;
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}