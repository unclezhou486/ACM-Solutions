#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+10);
	int maxid=-1,maxres=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxres){
			maxres=a[i];
			maxid=i;
		}
	}
	a[maxid]-=1;
	int maxx=0,minx=1e9;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]);
		minx=min(minx,a[i]);
		cnt+=a[i];
	}
	if(maxx-minx>k){
		cout<<"Jerry\n";
	}
	else{
		if(cnt%2){
			cout<<"Jerry\n";
		}
		else{
			cout<<"Tom\n";
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