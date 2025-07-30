#include <bits/stdc++.h>

using namespace std;

struct node{
	int pre=0,suf=0;
	int len=0;
	int cnt=0;
	long long sum=0;
	node operator+(const node &a) const{
		node c;
		c.sum=1ll*a.len*cnt+sum+a.sum;
		if(a.pre==1&&suf==1){
			c.sum=c.sum-a.len+2;
		}
		c.pre=pre;
		c.suf=a.suf;
		c.len=len+a.len;
		c.cnt=cnt+a.cnt;
		return c;
	}
};

node newnode(int x){
	node res;
	res.len=1;
	if(x==1){
		res.pre=res.suf=res.cnt=res.sum=1;
	}
	return res;
}

struct segmentTree{
	int n;
	vector<node> num;
	segmentTree(int n){
		init(n);
	}
	void init(int n){
		this->n=n;
		num.resize(n<<2);
	}
	void pushup(int rt){
		num[rt]=(num[rt<<1]+num[rt<<1|1]);
	}
	void modify(int rt,int x,int l,int r,int k){
		if(l==r){
			num[rt]=newnode(k);
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid) modify(rt<<1,x,l,mid,k);
		else modify(rt<<1|1,x,mid+1,r,k);
		pushup(rt);
	}
	void modify(int x,int k){
		modify(1,x,1,n,1);
	}
	node query(int rt,int x,int y,int l,int r){
		if(x<=l&&r<=y){
			return num[rt];
		}
		int mid=(l+r)>>1;
		node res;
		if(x<=mid) res=res+query(rt<<1,x,y,l,mid);
		if(mid<y) res=res+query(rt<<1|1,x,y,mid+1,r);
		return res;
	}
	node query(int x,int y){
		return query(1,x,y,1,n);
	}
};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	segmentTree seg(n);
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		a[i]=ch-'0';
		seg.modify(i,a[i]);
	}
	while(m--){
		int op;
		cin>>op;
		if(op==1){
			int l,r;
			cin>>l>>r;
			cout<<seg.query(l,r).sum<<'\n';
		}
		else{
			int x;
			cin>>x;
			a[x]^=1;
			seg.modify(x,a[x]);
		}
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