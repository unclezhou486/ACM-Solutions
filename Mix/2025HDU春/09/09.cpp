#include <bits/stdc++.h>

using namespace std;

constexpr int limit=2e5;

struct node{
	int xl,yl,xr,yr;
	bool operator<(const node &a) const{
		return yl<a.yl;
	}
};

struct segMentTree{
	vector<int> num;
	vector<int> lz;
	segMentTree(){
		num.assign(limit<<2,{});
		lz.assign(limit<<2,-1);
	}
	void pushup(int rt){
		num[rt]=max(num[rt<<1],num[rt<<1|1]);
	}
	void pushdown(int rt){
		if(lz[rt]!=-1){
			num[rt<<1]=max(num[rt<<1],lz[rt]);
			num[rt<<1|1]=max(num[rt<<1|1],lz[rt]);
			lz[rt<<1]=max(lz[rt],lz[rt<<1]);
			lz[rt<<1|1]=max(lz[rt],lz[rt<<1|1]);
			lz[rt]=-1;
		}
	}
	void update(int l,int r,int k,int x=0,int y=limit,int rt=1){
		if(l<=x&&y<=r){
			num[rt]=max(num[rt],k);
			lz[rt]=max(lz[rt],k);
			return;
		}
		pushdown(rt);
		int mid=(x+y)>>1;
		if(l<=mid) update(l,r,k,x,mid,rt<<1);
		if(mid<r) update(l,r,k,mid+1,y,rt<<1|1);
		pushup(rt);
	}
	int query(int l,int r,int x=0,int y=limit,int rt=1){
		if(l<=x&&y<=r){
			return num[rt];
		}
		pushdown(rt);
		int mid=(x+y)>>1;
		int res=-1;
		if(l<=mid) res=max(res,query(l,r,x,mid,rt<<1));
		if(mid<r) res=max(res,query(l,r,mid+1,y,rt<<1|1));
		return res;
	}
};

void solve(){
	int n;
	cin>>n;
	vector<node> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].xl>>a[i].yl>>a[i].xr>>a[i].yr;
	}	
	sort(a.begin(),a.end());
	segMentTree tr;
	vector<int> height(n);
	for(int i=0;i<n;i++){
		int h=tr.query(a[i].xl+1,a[i].xr);
		height[i]=a[i].yl-h;
		tr.update(a[i].xl+1,a[i].xr,h+(a[i].yr-a[i].yl));
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=1ll*(a[i].yr-a[i].yl)*(a[i].xr-a[i].xl)*(height[i]);
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