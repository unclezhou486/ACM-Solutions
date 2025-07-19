#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> num(n+10);
	vector<int> ans(q+10);
	for(int i=1;i<=q;i++){
		int x;
		cin>>x;
		if(x>0){
			num[x]+=1;
			ans[i]=x;
		}
		else{
			int minx=q+1;
			int minid=n+1;
			for(int j=1;j<=n;j++){
				if(num[j]<minx){
					minx=num[j];
					minid=j;
				}
			}
			num[minid]+=1;
			ans[i]=minid;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<" \n"[i==q];
	}
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
