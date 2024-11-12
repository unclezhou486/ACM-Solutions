#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,k,q;
	cin>>n>>k>>q;
	vector<vector<int> > a(n+10,vector<int>(k+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	vector<vector<int> > b(k+10,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			b[j][i]=b[j][i-1]|a[i][j];
		}
	} 
	for(int _=1;_<=q;_++){
		int m;
		cin>>m;
		int ll=1,rr=n;
		for(int i=1;i<=m;i++){
			int r,c;	
			char ch;
			cin>>r>>ch>>c;
			if(ll==n+1) continue;
			if(ch=='<'){
				auto it=lower_bound(b[r].begin()+1,b[r].end(),c);
				if(it==b[r].begin()+1){
					ll=n+1;
				}
				else{
					it--;
					int x=it-b[r].begin();
					rr=min(rr,x);
				}
			}
			else{
				auto it=upper_bound(b[r].begin()+1,b[r].end(),c);
				if(it==b[r].end()){
					ll=n+1;
				}
				else{
					int x=it-b[r].begin();
					ll=max(ll,x);
				}
			}			
		}
		if(ll!=n+1&&ll<=rr){
			cout<<ll<<'\n';
		}
		else{
			cout<<-1<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	// wihl
	solve();
	return 0;
}