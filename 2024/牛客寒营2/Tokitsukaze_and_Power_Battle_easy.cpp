#include <bits/stdc++.h>
#define pl tr<<1
#define pr tr<<1|1
#define int long long
using namespace std;

const int N=5e5+10;
int n,q;
int a[N],s[N];

struct segmentTree{
	int l,r,sum,lz; 
}t[N<<2];

void pushup(int tr){
	t[tr].sum=max(t[pl].sum,t[pr].sum);	
}

void pushdown(int tr){
	if(!t[tr].lz) return;
	t[pl].sum=(t[tr].lz+t[pl].sum);
	t[pr].sum=t[tr].lz+t[pr].sum;
	t[pl].lz+=t[tr].lz;
	t[pr].lz+=t[tr].lz;
	t[tr].lz=0;
}

void build(int l,int r,int tr){
	t[tr].l=l,t[tr].r=r;
	t[tr].sum=0,t[tr].lz=0;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pl);
	build(mid+1,r,pr);
	pushup(tr);
}

void update(int l,int r,int x,int tr){
	if(l<=t[tr].l&&t[tr].r<=r){
		t[tr].sum+=x;
		t[tr].lz+=x;
		return;
	}
	pushdown(tr);
	int mid=(t[tr].l+t[tr].r)>>1;
	if(l<=mid) update(l,r,x,pl);
	if(mid<r) update(l,r,x,pr);
	pushup(tr);
}

int query(int l,int r,int tr){
	if(l<=t[tr].l&&t[tr].r<=r){
		return t[tr].sum;
	}
	pushdown(tr);
	int ans=-1e18;
	int mid=(t[tr].l+t[tr].r)>>1;
	if(l<=mid) ans=max(query(l,r,pl),ans);
	if(mid<r) ans=max(query(l,r,pr),ans);
	return ans; 
}

int c[N];

int lowbit(int x){
	return x&-x;
}

void add(int k,int x){
//	cout<<"fu  "<<k<<' '<<x<<' '<<(k<=n)<<' '<<n<<'\n';
	for(k;k<=n;k+=lowbit(k)){
//		cout<<k<<' '<<x<<'\n';
		c[k]+=x;
	} 
}

int query1(int x){
	int res=0;
	for(;x;x-=lowbit(x)){
//		cout<<res<<' '<<c[x];
		res+=c[x];
	}
	return res;
}

void solve(){
	cin>>n>>q;
// 	memset(c,0,sizeof c);
    for(int i=0;i<=n;i++) c[i]=0;
	build(1,n,1);
	int res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,i,res-a[i],1);
		add(i,a[i]);
		res+=a[i];
	}
	while(q--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			update(x,x,(a[x]-y),1);
			add(x,y-a[x]);
			if(x!=n)update(x+1,n,(y-a[x]),1);
            a[x]=y;
		}
		else{
			cout<<query(x+1,y,1)-query1(x-1)<<'\n';
		}
	}
    build(1,n,1);
//	for(int i=1;i<=n;i++) c[i]=0; 
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}