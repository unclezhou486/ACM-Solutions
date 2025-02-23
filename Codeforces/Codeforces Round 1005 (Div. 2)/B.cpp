#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	vector<int> cnt(n+10);
	int id=1;
	int ans=0;
	int ansl=0,ansr=0,anslen=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]+=1;
	}
	for(int i=1;i<=n;i++){
		int x;
		// cin>>x;
		x=a[i];
		if(cnt[x]!=1){
			id=i+1;
		}
		if(id!=i+1){
			if(i-id+1>anslen){
				anslen=i-id+1;
				ansl=id,ansr=i;
			}
		}
	}
	if(anslen==0) cout<<0<<'\n';
	else cout<<ansl<<' '<<ansr<<'\n';

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