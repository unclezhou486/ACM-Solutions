#include<bits/stdc++.h>

using namespace std;

struct segment{
	int n;
	vector<vector<int> > num;
	// bitset<500010> bit;
	// vector<bitset<500010> > bit;
	void init(int n){
		this->n=n;
		num.assign(n*4,{});
		// bit.assign(n*4,{});
		// for(int i=0;i<n*4;i++){
		// 	bit[i][0]=1;
		// }
	}
	void update(int l,int r,int x,int y,int k,int rt){
		if(l<=x&&y<=r){
			num[rt].push_back(k);
			return;
		}
		int mid=(x+y)>>1;
		if(l<=mid) update(l,r,x,mid,k,rt<<1);
		if(mid<r) update(l,r,mid+1,y,k,rt<<1|1);
	}
	// int query(int l,int r,int k,int rt){
	// 	if(num[rt].size()){
	// 		for(auto x:num[rt]){
	// 			bit[rt]|=bit[rt]<<x;
	// 			num[rt<<1].push_back(x);
	// 			num[rt<<1|1].push_back(x);
	// 		}
	// 		num[rt].clear();
	// 	}
	// 	if(l==r){
	// 		return bit[rt].count()-1;
	// 	}
	// 	int mid=(l+r)>>1;
	// 	if(k<=mid) return query(l,mid,k,rt<<1);
	// 	if(mid<k) return query(mid+1,r,k,rt<<1|1);
	// }
	void dfs(int l,int r,bitset<500010> bit,int rt){
		// bit[0]=1;
		for(auto x:num[rt]){
			bit|=bit<<x;
		}
		if(l==r){
			cout<<bit.count()-1<<'\n';
			return;
		}
		int mid=(l+r)>>1;
		dfs(l,mid,bit,rt<<1);
		dfs(mid+1,r,bit,rt<<1|1);
	}
}seg;

void solve(){
	int n;
	cin>>n;
	vector<vector<int> > la(500010);
	seg.init(n+10);
	for(int i=1;i<=n;i++){
		int op,x;
		cin>>op>>x;
		if(op==1){
			la[x].push_back(i);
		}
		else{
			if(la[x].size()){
				int y=la[x].back();
				la[x].pop_back();
				seg.update(y,i-1,1,n,x,1);
			}
		}
	}
	for(int i=1;i<=500010;i++){
		if(la[i].size()){
			for(auto x:la[i]){
				seg.update(x,n,1,n,i,1);
			}
		}
	}
	bitset<500010> bit;
	bit[0]=1;
	seg.dfs(1,n,bit,1);
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
