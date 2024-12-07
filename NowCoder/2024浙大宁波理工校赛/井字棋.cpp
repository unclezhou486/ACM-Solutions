#include <bits/stdc++.h>

using namespace std;

int a[10],b[10],c[10],d[10];

void solve(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			char ch;
			cin>>ch;
			if(ch=='O'){
				a[i]+=1;
				b[j]+=1;
				c[i+j]+=1;
				d[i-j+3]+=1;
			}
			else if(ch=='X'){
				a[i]-=1;
				b[j]-=1;
				c[i+j]-=1;
				d[i-j+3]-=1;
			}
		}
	}
	bool flag=false;
	for(int i=1;i<=3;i++){
		if(a[i]==3||b[i]==3){
			flag=true;
		}
	}
	for(int i=2;i<=6;i++){
		if(c[i]==3){
			flag=true;
		}
	}
	for(int i=1;i<=5;i++){
		if(d[i]==3){
			flag=true;
		}
	}
	if(flag){
		cout<<"lumo win!\n";
	}
	else cout<<"Qfish win!\n";
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