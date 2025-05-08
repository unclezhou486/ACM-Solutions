#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> > a(n+10,vector<int>(m+10) ) ;
	vector<int> cnt(k+10);
	int count=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int idx=m;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=idx;j++){
			if(cnt[a[i][j]]==0){
				count+=1;
			}
			cnt[a[i][j]]+=1;
		}
		while(count==k){
			bool flag=true;
			for(int j=1;j<=i;j++){
				if(cnt[a[j][idx]]==1){
					flag=false;
				}
				cnt[a[j][idx]]-=1;
			}
			if(flag==false){
				for(int j=1;j<=i;j++){
					if(cnt[a[j][idx]]==0){
						// count++;
					}
					cnt[a[j][idx]]+=1;
				}
				break;
			}
			idx--;
		}
		if(count==k) ans+=(m-idx+1);
	}
	cout<<ans<<'\n';
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