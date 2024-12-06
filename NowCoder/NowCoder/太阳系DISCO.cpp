#include <bits/stdc++.h>
#define int long long
using namespace std;

queue<int> q;
void solve(){
	int n,k,a,b,x,y;
	cin>>n>>k>>a>>b>>x>>y;
	vector<int> d(n+10,1e18);
	a--,b--;
	q.push(a);
	d[a]=1;
	if(a==b){
		cout<<0<<'\n';
		return;
	}
	while(q.size()){
		int pos=q.front();
		q.pop();
		if(d[(pos+x)%n]>d[pos]+1){
			d[(pos+x)%n]=d[pos]+1;
			q.push((pos+x)%n);
		}
		if(d[(pos-y+n)%n]>d[pos]+1){
			d[(pos-y+n)%n]=d[pos]+1;
			q.push((pos-y+n)%n);
		}
	}
	for(int i=1;i<=k;i++){
		bool flag=true;
		for(int i=0;i<n;i++){
			if(d[i]!=1e18&&d[(i+n/2)%n]>d[i]+1){
				d[(i+n/2)%n]=d[i]+1;
				flag=false;
				q.push((i+n/2)%n);
			}
		}
		while(q.size()){
			int pos=q.front();
			q.pop();
			if(d[(pos+x)%n]>d[pos]+1){
				d[(pos+x)%n]=d[pos]+1;
				q.push((pos+x)%n);
			}
			if(d[(pos-y+n)%n]>d[pos]+1){
				d[(pos-y+n)%n]=d[pos]+1;
				q.push((pos-y+n)%n);
			}
		}
		if(flag) break;
	}
	if(d[b]!=1e18) cout<<d[b]-1<<'\n';
	else cout<<-1<<'\n';
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)solve();
	return 0;
}