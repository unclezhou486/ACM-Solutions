#include <bits/stdc++.h>

using namespace std;

const int N=4e5+10;
const int INF=0x3f3f3f3f;

int n,k,q;
int a[N];
int cnt[N],res[N];
int ans[N];

long long anss[N];

stack<pair<int,int> > st;

struct SegmentTree{
	long long sum;
	int lz=INF;
}t[N<<2];

struct node{
	int l,r,id;
	bool operator<(const node &a){
		return l>a.l;
	}
}qu[N];


void pushup(int tr){
	t[tr].sum=t[tr<<1].sum+t[tr<<1|1].sum;
}

void pushdown(int tr,int l,int r){
	int mid=(l+r)>>1;
	if(t[tr].lz!=INF){
		t[tr<<1].sum=1ll*(mid-l+1)*t[tr].lz;
		t[tr<<1|1].sum=1ll*(r-(mid+1)+1)*t[tr].lz;
		t[tr<<1].lz=min(t[tr].lz,t[tr<<1].lz);
		t[tr<<1|1].lz=min(t[tr].lz,t[tr<<1].lz);
		t[tr].lz=INF;
	}
}

void update(int l,int r,int k,int x=1,int y=n,int tr=1){
	if(l<=x&&y<=r){
		t[tr].sum=1ll*(y-x+1)*k;
		t[tr].lz=k;
		return;
	}
	pushdown(tr,x,y);
	int mid=(x+y)>>1;
	if(l<=mid)update(l,r,k,x,mid,tr<<1);
	if(mid<r) update(l,r,k,mid+1,y,tr<<1|1);
	pushup(tr);
}

long long query(int l,int r,int x=1,int y=n,int tr=1){
	if(l<=x&&y<=r){
		return t[tr].sum;
	}
	pushdown(tr,x,y);
	int mid=(x+y)>>1;
	long long res=0;
	if(l<=mid) res+=query(l,r,x,mid,tr<<1);
	if(mid<r) res+=query(l,r,mid+1,y,tr<<1|1);
	return res;
}

void init(int x=1,int y=n,int tr=1){
	t[tr].sum=0,t[tr].lz=INF;
	if(x==y) return;
	int mid=x+y>>1;
	init(x,mid,tr<<1);
	init(mid+1,y,tr<<1|1);
}

void solve(){
	cin>>n>>k>>q;
	init();
	int ress=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]-i+n;
	}
	for(int i=1;i<=k;i++){
		cnt[a[i]]+=1;
		res[cnt[a[i]]]+=1;
		ress=max(ress,cnt[a[i]]);
	}
	ans[1]=k-ress;
	for(int i=k+1;i<=n;i++){
		int l=i-k+1;
		res[cnt[a[l-1]]]-=1;
		if(!res[cnt[a[l-1]]]&&ress==cnt[a[l-1]]) ress-=1;
		cnt[a[l-1]]-=1;
		cnt[a[i]]+=1;
		res[cnt[a[i]]]+=1;
		ress=max(ress,cnt[a[i]]);
		ans[l]=k-ress;
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i].l>>qu[i].r;
		qu[i].id=i;
	}
	sort(qu+1,qu+1+q);
    while(st.size()) st.pop();
	st.push({-1,n-k+2});
	int id=n-k+2;
	//1 2 3 4 5 6
	for(int i=1;i<=q;i++){
		while(id>qu[i].l){
			id--;
			while(st.size()&&st.top().first>=ans[id]){
				st.pop();
			}
			update(id,st.top().second-1,ans[id]);
			st.push({ans[id],id});
		}
		anss[qu[i].id]=query(qu[i].l,qu[i].r-k+1);
	}
	for(int i=1;i<=q;i++){
		cout<<anss[i]<<'\n';
	}
	
	for(int i=0;i<=2*n;i++){
		cnt[i]=res[i]=0;
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
/*

1
8 4 2
4 3 1 1 2 4 3 2
3 6
1 5


*/