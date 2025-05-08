#include <bits/stdc++.h>

using namespace std;



void solve(){
	int n;
	cin>>n;
	vector<int> deg(n+10),checked(n+10),nxt(n+10);
	for(int i=1;i<=n;i++){
		cin>>nxt[i];
		deg[nxt[i]]+=1;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(!deg[i]){
			q.push(i);
		}
	}
	int ans=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		ans++;
		checked[x]=1;
		if(!checked[nxt[x]]){
			checked[nxt[x]]=1;
			deg[nxt[nxt[x]]]-=1;
			if(!deg[nxt[nxt[x]]]) q.push(nxt[nxt[x]]);
		}
	}
	for(int i=1;i<=n;i++){
		if(!checked[i]){
			int cnt=0;
			while(!checked[i]){
				cnt+=1;
				checked[i]=1;
				i=nxt[i];
			}
			ans+=cnt/2;
		}
	}
	cout<<ans<<'\n';
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