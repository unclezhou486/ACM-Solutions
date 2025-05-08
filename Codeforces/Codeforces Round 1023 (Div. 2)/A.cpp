#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	int maxid=-1,maxres=0;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxres){
			maxid=i;
			maxres=a[i];
		}
		if(i>1&&a[i]!=a[i-1]){
			flag=true;
		}
	}
	if(flag==false){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
		for(int i=1;i<=n;i++){
			cout<<(i==maxid?1:2)<<" \n"[i==n];
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