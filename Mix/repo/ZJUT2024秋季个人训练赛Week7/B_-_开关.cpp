#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;


int n,m;
struct node{
	int num,lz;
}t[N<<2];

void build(int l,int r,int tr){
	t[tr].num=t[tr].lz=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,tr<<1);
	build(mid+1,r,tr<<1|1);
}

void pushdown(int tr,int x,int y){
	int mid=(x+y)>>1;
	if(!t[tr].lz) return;
	t[tr<<1].num=(mid-x+1)-t[tr<<1].num;
	t[tr<<1|1].num=(y-mid)-t[tr<<1|1].num;
	t[tr<<1].lz^=t[tr].lz;
	t[tr<<1|1].lz^=t[tr].lz;
	t[tr].lz=0;
}

void update(int l,int r,int tr=1,int x=1,int y=n){
	if(l<=x&&y<=r){
		t[tr].num=(y-x+1)-t[tr].num;
		t[tr].lz^=1;
		return;
	}
	pushdown(tr,x,y);
	int mid=(x+y)>>1;
	if(l<=mid) update(l,r,tr<<1,x,mid);
	if(mid<r) update(l,r,tr<<1|1,mid+1,y);
	t[tr].num=t[tr<<1].num+t[tr<<1|1].num;
}

int query(int l,int r,int tr=1,int x=1,int y=n){
	if(l<=x&&y<=r){
		return t[tr].num;
	}
	pushdown(tr,x,y);
	int mid=(x+y)>>1;
	int res=0;
	if(l<=mid) res+=query(l,r,tr<<1,x,mid);
	if(mid<r) res+=query(l,r,tr<<1|1,mid+1,y);
	return res;
}


void solve(){
	cin>>n>>m;
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int op;
		int x,y;
		cin>>op>>x>>y;
		if(op==0){
			update(x,y);
		}
		else{
			cout<<query(x,y)<<'\n';
		}
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