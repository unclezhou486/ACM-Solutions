#include<bits/stdc++.h>

using namespace std;

constexpr int mod=1e9;
constexpr int limit=1e9;

struct segMentTree{
	int tot=1;
	int root=1;
	vector<long long> sum0,sum1;
	vector<int> ls,rs,cnt,lz;
	segMentTree(int n){
		sum0.assign(n*32,{});
		sum1=sum0;
		cnt.assign(n*32,{});
		lz=ls=rs=cnt;
		tot=1;
		root=1;
	}
	void pushup(int rt){
		sum0[rt]=sum0[ls[rt]]+sum0[rs[rt]];
		sum1[rt]=sum1[ls[rt]]+sum1[rs[rt]];
		cnt[rt]=cnt[ls[rt]]+cnt[rs[rt]];
	}
	void pushdown(int rt){
		if(lz[rt]){
			swap(sum0[ls[rt]],sum1[ls[rt]]);
			swap(sum0[rs[rt]],sum1[rs[rt]]);
			lz[rt]=0;
			lz[ls[rt]]^=1;
			lz[rs[rt]]^=1;
		}
	}
	void update(int x,int op,int &rt,int l=0,int r=limit){
		if(!rt) rt=++tot;
		if(l==r){
			if(op==1){
				sum1[rt]+=x;
			}
			else{
				sum0[rt]+=x;
			}
			cnt[rt]+=1;
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if(x<=mid) update(x,op,ls[rt],l,mid);
		if(mid<x) update(x,op,rs[rt],mid+1,r);
		pushup(rt);
	}
	void update(int x,int op){
		update(x,op,root);
	}
	void rev(int x,int y,int rt=1,int l=0,int r=limit){
		if(!rt) return;
		if(x<=l&&r<=y){
			swap(sum0[rt],sum1[rt]);
			lz[rt]^=1;
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if(x<=mid) rev(x,y,ls[rt],l,mid);
		if(mid<y) rev(x,y,rs[rt],mid+1,r);
		pushup(rt);
	}
	int count(int x,int y,int rt=1,int l=0,int r=limit){
		if(!rt) return 0;
		if(x<=l&&r<=y){
			return cnt[rt];
		}
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid) res+=count(x,y,ls[rt],l,mid);
		if(mid<y) res+=count(x,y,rs[rt],mid+1,r);
		return res; 
	}
};

void solve(){
	int q;
	cin>>q;
	long long z=0;
	segMentTree tr(q);
	for(int i=1;i<=q;i++){
		int y;
		cin>>y;
		int x=(y+z)%mod+1;
		tr.rev(x,limit);
		int cnt=tr.count(0,x-1);
		tr.update(x,(cnt+1)%2);
		z=tr.sum1[1];
		cout<<z<<'\n';
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
