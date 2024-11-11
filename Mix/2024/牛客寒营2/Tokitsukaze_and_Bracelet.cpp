#include <bits/stdc++.h>

using namespace std;

int n;

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int res=0;
	res+=(a-100)/50;
	if(b>33&&b<41) res+=1;
	else if(b==45) res+=2;
	if(c>33&&c<41) res+=1;
	else if(c==45) res+=2;
	cout<<res<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		solve();
	}
	return 0;
} 