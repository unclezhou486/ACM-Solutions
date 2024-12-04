#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int n;
int maxn=200000;

struct SegmentTree{
	int root[N];
	int tot=0;
	int n;
	int ls[N*20],rs[N*20];
	long long sum[N*20];
	void init(int n){
		this->n=n;
		memset(ls,0,sizeof ls);
		memset(rs,0,sizeof rs);
		memset(root,0,sizeof root);
		memset(sum,0,sizeof sum);
	}
	void update(int l,int r,int k,int &tr,int pre,int x,int y){
		if(!tr) tr=++tot;
		sum[tr]=sum[pre];
		sum[tr]+=k;
		if(x==y) return;
		int mid=(x+y)>>1;
		if(l<=mid) update(l,r,k,ls[tr],ls[pre],x,mid);
		if(mid<r) update(l,r,k,rs[tr],rs[pre],mid+1,y);
		if(!ls[tr]) ls[tr]=ls[pre];
		if(!rs[tr]) rs[tr]=rs[pre];
	}
	void update(int l,int r,int k,int &tr,int pre){
		update(l,r,k,tr,pre,1,n);
	}
	long long query(int l,int r,int &tr,int pre,int x,int y){
		if(!tr) return 0;
		if(l<=x&&y<=r){
			return sum[tr]-sum[pre];
		}
		int mid=(x+y)>>1;
		long long res=0;
		if(l<=mid) res+=query(l,r,ls[tr],ls[pre],x,mid);
		if(mid<r) res+=query(l,r,rs[tr],rs[pre],mid+1,y);
		return res;
	}
	long long query(int l,int r,int &tr,int pre){
		return query(l,r,tr,pre,1,n);
	}
}t1,t2,ta1,ta2,tb1,tb2;


void solve(){
	cin>>n;
	t1.init(N-5);
	t2.init(N-5);
	ta1.init(N-5);
	ta2.init(N-5);
	tb2.init(N-5);
	tb1.init(N-5);
	for(int i=1;i<=n;i++){
		long long x1,x2,y1,y2,a,b;
		cin>>x1>>x2>>y1>>a>>b>>y2;
		t1.update(x1,x1,y1,t1.root[i],t1.root[i-1]);
		t2.update(x2,x2,y2,t2.root[i],t2.root[i-1]);
		ta1.update(x1,x1,a,ta1.root[i],ta1.root[i-1]);
		ta2.update(x2,x2,a,ta2.root[i],ta2.root[i-1]);
		tb1.update(x1,x1,b,tb1.root[i],tb1.root[i-1]);
		tb2.update(x2,x2,b,tb2.root[i],tb2.root[i-1]);
	}
	int m;
	cin>>m;
	long long last=0;
	while(m--){
		int l,r;
		long long x;
		cin>>l>>r>>x;
		x+=last;x%=1000000000;
		int xx=x;
		if(xx>maxn+3) xx=maxn+3;
		long long res=0;
		res=t1.query(xx,maxn,t1.root[r],t1.root[l-1]);
		res+=t2.query(1,xx-1,t2.root[r],t2.root[l-1]);
		long long resa=0,resb=0;
		resa+=ta1.query(1,xx-1,ta1.root[r],ta1.root[l-1]);
		resa-=ta2.query(1,xx-1,ta2.root[r],ta2.root[l-1]);
		resb-=tb2.query(1,xx-1,tb2.root[r],tb2.root[l-1]);
		resb+=tb1.query(1,xx-1,tb1.root[r],tb1.root[l-1]);
		res+=resb;
		res+=resa*x;
		last=res;
		cout<<last<<'\n';
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