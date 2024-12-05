#include <bits/stdc++.h>

using namespace std;

constexpr int N=2e5+10;

int h,w,n;

int num[N<<2];
int lz[N<<2];
int ans[N];

struct node{
	int r,c,len,id;
	bool operator < (const node &a) const{
		return r>a.r;
	}
}a[N];

void pushup(int tr){
	num[tr]=max(num[tr<<1],num[tr<<1|1]);
}

void pushdown(int tr){
	if(lz[tr]){
		num[tr<<1]=lz[tr];
		num[tr<<1|1]=lz[tr];
		lz[tr<<1]=lz[tr];
		lz[tr<<1|1]=lz[tr];
		lz[tr]=0;
	}
}

void update(int l,int r,int k,int tr=1,int x=1,int y=w){
	if(l<=x&&y<=r){
		num[tr]=k;
		lz[tr]=k;
		return;
	}
	pushdown(tr);
	int mid=(x+y)>>1;
	if(l<=mid) update(l,r,k,tr<<1,x,mid);
	if(mid<r) update(l,r,k,tr<<1|1,mid+1,y);
	pushup(tr);
}

int query(int l,int r,int tr=1,int x=1,int y=w){
	if(l<=x&&y<=r){
		return num[tr];
	}
	pushdown(tr);
	int mid=(x+y)>>1;
	int res=0;
	if(l<=mid) res=max(query(l,r,tr<<1,x,mid),res);
	if(mid<r) res=max(query(l,r,tr<<1|1,mid+1,y),res);
	return res;
}

void solve(){
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].r>>a[i].c>>a[i].len;
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans[a[i].id]=query(a[i].c,a[i].c+a[i].len-1)+1;
		update(a[i].c,a[i].c+a[i].len-1,ans[a[i].id]);
	}
	for(int i=1;i<=n;i++){
		cout<<h-ans[i]+1<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}