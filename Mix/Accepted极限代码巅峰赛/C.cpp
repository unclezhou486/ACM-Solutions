#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,m,q;
int a[N],b[N];

struct node{
	unordered_map<int,int> ma;
	unordered_map<int,int> maa;
}t[N<<2];

void merge(node &x,node &y,node &z){
	for(auto [la,lb]:y.ma){
		x.ma[la]=lb;
	}
	unordered_map<int,int> ma;
	for(auto [ra,rb]:z.ma){
		int res1,res2;
		if(x.ma.count(rb)) res2=x.ma[rb];
		else res2=rb;
		// if(x.ma.count(res2)) res1=x.ma[res2];
		// else res1=res2;
		ma[ra]=res2;		
		// x.ma[ra]=res2,x.ma[rb]=res1;
	}
	for(auto [a,b]:ma){
		x.ma[a]=b;
	}
	// for(auto [a,b]:)
	return;
}

void build(int l=1,int r=m,int tr=1){
	if(l==r){
		t[tr].ma[a[l]]=b[l];
		t[tr].ma[b[l]]=a[l];
		t[tr].maa[a[l]]=b[l];
		t[tr].maa[b[l]]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,tr<<1);
	build(mid+1,r,tr<<1|1);
	merge(t[tr],t[tr<<1],t[tr<<1|1]);
	for(auto [x,y]:t[tr].ma){
		t[tr].maa[y]=x;
	}
}

node query(int l,int r,int k,int x=1,int y=m,int tr=1){
	if(l<=x&&y<=r){
		return t[tr];
	}
	int mid=(x+y)>>1;
	node res;
	if(l<=mid){
		res=query(l,r,k,x,mid,tr<<1);
	}
	if(mid<r){
		node ress=query(l,r,k,mid+1,y,tr<<1|1);
		int kk=res.ma[k];
		if(!kk) kk=k;
		if(ress.ma.count(kk)){
			res.ma[k]=ress.maa[kk];
		}
		// merge(res,res,ress);
	}
	return res;
}
void solve(){
	// int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	build();
	for(int i=1;i<=q;i++){
		int l,r,k;
		cin>>l>>r>>k;
		node res=query(l,r,k);
		if(res.maa.count(k)) cout<<res.ma[k]<<'\n';
		else cout<<k<<'\n';
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