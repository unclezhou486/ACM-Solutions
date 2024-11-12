#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x=0;
	for(int i=1;i<=100;i++){
		x^=i;
		cout<<x<<'\n';
	}
}