#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> ans(n+10);
	int x=1;
	int i;
	for(i=1;i+7<=n;i+=7){
		ans[i]=ans[i+1]=ans[i+4]=x;
		ans[i+2]=ans[i+5]=x+1;
		ans[i+3]=x+2;
		ans[i+6]=x+2;
		x+=3;
	}
	if(n%7<=4&&n%7>=1){
		ans[i]=ans[i+2]=x;
		ans[i+1]=x-1;
		ans[i+3]=x+1;
	}
	else{
		ans[i]=ans[i+1]=ans[i+4]=x;
		ans[i+2]=ans[i+5]=x+1;
		ans[i+3]=x+2;
		ans[i+6]=x+2;
		x+=3;		
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
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