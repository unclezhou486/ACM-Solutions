#include <bits/stdc++.h>

using namespace std;

struct Bit{
	int n;
	vector<int> bit;
	void init(int n){
		this->n=n;
		bit.assign(n+10,{});
	}
	int lowbit(int x){
		return x&-x;
	}
	void add(int k,int x){
		for(;k<=n;k+=lowbit(k)){
			bit[k]+=x;
		}
	}
	int query(int x){
		int res=0;
		for(;x;x-=lowbit(x)){
			res+=bit[x];
		}
		return res;
	}
}bit;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10),id(n+10),b(n+10);
	vector<int> ans(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		id[a[i]]=i;
	}
	bit.init(n);
	for(int i=1;i<=n;i++){
		cin>>b[i];
		ans[b[i]]=id[b[i]]-1+((i-1)-bit.query(id[b[i]]-1));
		bit.add(id[b[i]],1);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
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