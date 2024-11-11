#include <bits/stdc++.h>

using namespace std;

struct BIT{
	int n;
	vector<int> a;
	BIT(int _n=0){
		init(_n);
	}
	void init(int _n){
		n=_n+10;
		a.assign(n,{});
	}
	void add(int x,int v){
		for(int i=x+1;i<=n;i+= i&-i){
			a[i]=a[i]+v;
		}
	}
	int sum(int x){
		int ans=0;
		for(int i=x+1;i>0;i-=i&-i){
			ans=ans+a[i];
		}
		return ans;
	}
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
};

struct node{
	int r,id;
};

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> h(n+10);
	BIT bit(n);
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	vector<vector<node> > qu(n+10);
	vector<int> ans(q);
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		qu[l].push_back((node){r,i});
	}
	stack<int> st;
	for(int i=n;i>=1;i--){
		for(auto [r,id]:qu[i]){
			ans[id]=bit.query(r+1,n);
			// cout<<i<<' '<<r<<' '<<ans[id]<<'\n';
		}
		while(!st.empty()&&h[st.top()]<h[i]){
			bit.add(st.top(),-1);
			st.pop();
		}
		st.push(i);
		bit.add(i,1);
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;;
	while(t--){
		solve();
	}
	return 0;
}