#include<bits/stdc++.h>

using namespace std;

struct node{
	long long val=0,need=0;
};

node merge(node a,node b){
	node c;
	c.val=b.val+max(a.val-b.need,0ll);
	c.need=a.need+max(b.need-a.val,0ll);
	return c;
};

struct segmentTree{
	int n;
	vector<node> vec;
	void init(int n){
		this->n=n;
		vec.assign(n<<2,{});
	}
	void modify(int rt,int x,int l,int r,long long k1,long long k2){
		if(l==r){
			vec[rt]=(node){k1,k2};
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid) modify(rt<<1,x,l,mid,k1,k2);
		if(mid<x) modify(rt<<1|1,x,mid+1,r,k1,k2);
		vec[rt]=merge(vec[rt<<1],vec[rt<<1|1]);
	}
	void modify(int x,long long k1,long long k2){
		modify(1,x,1,n,k1,k2);
	}
	node query(int rt,int x,int y,int l,int r){
		if(x>y){
			return (node){0,0};
		}
		if(x<=l&&r<=y){
			return vec[rt];
		}
		int mid=(l+r)>>1;
		node resl,resr;
		if(x<=mid) resl=query(rt<<1,x,y,l,mid);
		if(mid<y) resr=query(rt<<1|1,x,y,mid+1,r);
		node res=merge(resl,resr);
		return res;
	}
	node query(int x,int y){
		return query(1,x,y,1,n);
	}
}seg;

struct line{
	int v,op,x,y;
	line(int a,int b,int c,int d):v(a),op(b),x(c),y(d){}
};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+10),b(n+10);
	vector<vector<line> > adj(m+10);
	vector<vector<int> > qu(m+10);
	vector<int> opp(m+10);
	vector<long long > ans(m+10);
	seg.init(n);
	long long suma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		suma+=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		seg.modify(i,max(a[i]-b[i],0),max(b[i]-a[i],0));
	}
	for(int i=1;i<=m;i++){
		int op,x,y;
		cin>>op;
		opp[i]=op;
		if(op==1||op==2){
			cin>>x>>y;
			adj[i-1].emplace_back(i,op,x,y);
		}
		else if(op==3){
			cin>>x;
			adj[x].emplace_back(i,3,0,0);
		}
		else{
			int k;
			cin>>k;
			vector<int> id(k);
			for(int j=0;j<k;j++){
				cin>>id[j];
			}
			qu[i]=id;
			adj[i-1].emplace_back(i,4,0,0);
		}
	}
	auto dfs = [&](auto self,int u) -> void{
		if(opp[u]==4){
			vector<int> vec = qu[u];
			int k=vec.size();
			node res;
			int idl=1;
			for(int i=0;i<k;i++){
				res=merge(res,seg.query(idl,vec[i]-1));
				res.val+=a[vec[i]];
				res.val/=2;
				idl=vec[i]+1;
			}
			res=merge(res,seg.query(idl,n));
			ans[u]=suma-res.val;
		}
		for(auto [v,op,x,y]:adj[u]){
			int oria=a[x],orib=b[x];
			if(op==1){
				suma-=a[x];
				a[x]=y;
				suma+=a[x];
				seg.modify(x,max(a[x]-b[x],0),max(b[x]-a[x],0));
			}
			else if(op==2){
				b[x]=y;
				seg.modify(x,max(a[x]-b[x],0),max(b[x]-a[x],0));
			}
			self(self,v);
			if(op==1){
				suma-=a[x];
				a[x]=oria;
				suma+=a[x];
				seg.modify(x,max(a[x]-b[x],0),max(b[x]-a[x],0));
			}
			else if(op==2){
				b[x]=orib;
				seg.modify(x,max(a[x]-b[x],0),max(b[x]-a[x],0));
			}
		}
	};
	dfs(dfs,0);
	for(int i=1;i<=m;i++){
		if(opp[i]==4){
			cout<<ans[i]<<'\n';
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
