#include <bits/stdc++.h>

using namespace std;

constexpr int N=5e4+10;

int n,m;

struct node{
	vector<int> a;
}a[N];

vector<int> ans;

bool check(int x){
	vector<vector<int> > adj(n+10);
	vector<int> in(n+10),out(n+10);
	for(int i=1;i<=x;i++){
		for(int j=1;j<a[i].a.size();j++){
			adj[a[i].a[j-1]].push_back(a[i].a[j]);
			in[a[i].a[j]]++;
			out[a[i].a[j-1]]++;
		}
	}
	priority_queue<int,vector<int>,greater<int> > q;
	// vector<int> ans;
	ans.clear();
	for(int i=1;i<=n;i++){
		if(!in[i]){
			q.push(i);
		}
	}
	while(q.size()){
		int x=q.top();
		ans.push_back(x);
		q.pop();
		for(auto y:adj[x]){
			in[y]--;
			if(!in[y]){
				q.push(y);
			}
		}
	}
	if(ans.size()==n) return 1;
	else return 0;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x;
			cin>>x;
			a[i].a.push_back(x);
		}
	}
	int l=0,r=m;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
    check(l);
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" \n"[i==n];
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