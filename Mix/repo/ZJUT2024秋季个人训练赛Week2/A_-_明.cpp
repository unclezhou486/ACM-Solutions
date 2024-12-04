#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int n,m;

int a[N];

struct node{
	int sum;
	int lz1,lz2;
}t[N<<2];

void pushup(int tr){
	t[tr].sum=(t[tr<<1].sum+t[tr<<1|1].sum);
}

void pushdown(int tr,int l,int r){
	if(t[tr].lz2){//0
		t[tr<<1].sum=0,t[tr<<1].lz2=1,t[tr<<1|1].lz1=0;
		t[tr<<1|1].sum=0,t[tr<<1|1].lz2=1,t[tr<<1|1].lz1=0;
		t[tr].lz2=0;
	}
	if(t[tr].lz1){//^=1
		int mid=(l+r)>>1;
		t[tr<<1].sum=(mid-l+1-t[tr<<1].sum),t[tr<<1].lz1^=1;
		t[tr<<1|1].sum=(r-(mid+1)+1-t[tr<<1|1].sum),t[tr<<1|1].lz1^=1;
		t[tr].lz1=0;
	}
}

void update1(int l,int r,int k,int x=1,int y=n,int tr=1){//
	if(l<=x&&y<=r){
		t[tr].sum=(y-x+1)-t[tr].sum;
		t[tr].lz1^=1;
	}
	pushdown(tr,x,y);
	int mid=x+y>>1;
	if(l<=mid) update1(l,r,k,x,mid,tr<<1);
	if(mid<r) update1(l,r,k,mid+1,y,tr<<1|1);
	pushup(tr);
}

void update2(int l,int r,int k,int x=1,int y=n,int tr=1){
	if(l<=x&&y<=r){
		t[tr].sum=0;
		t[tr].lz2=1;
	}
	pushdown(tr,x,y);
	int mid=x+y>>1;
	if(l<=mid) update2(l,r,k,x,mid,tr<<1);
	if(mid<r) update2(l,r,k,mid+1,y,tr<<1|1);
	pushup(tr);
}

int query(int l,int r,int x=1,int y=n,int tr=1){
	if(l<=x&&y<=r){
		return t[tr].sum;
	}
	pushdown(tr,x,y);
	int mid=(x+y)>>1;
	int res=0;
	if(l<=mid)  res+=query(l,r,x,mid,tr<<1);
	if(mid<r) res+=query(l,r,mid+1,y,tr<<1|1);
	return res;
}


void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];

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