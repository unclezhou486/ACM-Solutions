#include<bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int mod=39989;
constexpr int mod1=1e9;

template<class T>
struct lichaoTree{
	int n;
	int root=1;
	vector<int> id;
	vector<pair<T,T> > line;
	long double eps=1e-6;
	int cntid=0;
	lichaoTree(){}
	lichaoTree(int n){
		init(n);
	}
	lichaoTree(int n,vector<pair<T,T> > &vec){
		init(n,vec);
	}
	void init(int n){
		this->n=n;
		id.assign(n<<2,{});
		line.clear();
		line.emplace_back(0,0);
		cntid=0;
	}
	void init(int n,vector<pair<T,T> > &vec){
		this->n=n;
		id.assign(n<<2,{});
		line=vec;
		cntid=line.size()-1;
	}
	void print(){
		cout<<"LINE:\n";
		for(int i=1;i<=cntid;i++){
			cout<<line[i].first<<' '<<line[i].second<<"\n";
		}
	}
	T calc(int idx,int x){
		return line[idx].first*x+line[idx].second;
	}
	int cmpT(T a,T b){
		if(a-b>eps){
			return 1;
		}
		else if(a-b<-eps){
			return -1;
		}
		else{
			return 0;
		}
	}
	bool cmp(int u,int v,int x){
		T calu=calc(u,x),calv=calc(v,x);
		if(cmpT(calu,calv)==1||cmpT(calu,calv)==0&&u<v){
			return 1;
		}
		else{
			return 0;
		}
	}
	pair<T,int> pairmax(pair<T,int> a,pair<T,int> b){
		if(cmpT(a.first,b.first)==1||(cmpT(a.first,b.first)==0&&a.second<b.second)) return a;
		else return b;
	}
	void upd(int rt,int l,int r,int u){
		int &v = id[rt];
		int mid=(l+r)>>1;
		if(cmp(u,v,mid)) swap(u,v);
		if(cmp(u,v,l)) upd(rt<<1,l,mid,u);
		if(cmp(u,v,r)) upd(rt<<1|1,mid+1,r,u);
	}
	void update(int rt,int x,int y,int l,int r,int u){
		if(x<=l&&r<=y){
			upd(rt,l,r,u);
			return;

		}
		int mid=(l+r)>>1;
		if(x<=mid) update(rt<<1,x,y,l,mid,u);
		if(mid<y) update(rt<<1|1,x,y,mid+1,r,u);
	}
	void update(int x,int y,int u){
		update(root,x,y,1,n,u);
	}
	void add(int xa,int ya,int xb,int yb){
		if(xa==xb){
			line.emplace_back(0,max(ya,yb));
		}
		else{
			T k,b;
			k=1.0*(yb-ya)/(xb-xa);
			b=yb-xb*k;
			line.emplace_back(k,b);
		}
		cntid+=1;
		update(xa,xb,cntid);
	}
	void add(T k,T b){// usually x = [1,n]
		line.emplace_back(k,b);
 		cntid+=1;
 		update(1,n,cntid);
	}
	//y=3-2x 
	pair<T,int > query(int rt,int l,int r,int x){
		if(l==r){
			return {calc(id[rt],x),id[rt]};
		}
		int mid=(l+r)>>1;
		pair<T,int> res = {calc(id[rt],x),id[rt]};
		if(x<=mid) res=pairmax(res,query(rt<<1,l,mid,x));
		if(mid<x) res=pairmax(res,query(rt<<1|1,mid+1,r,x));
		return res;
	}
	T queryid (int x){
		return query(root,1,n,x).second;
	}
	T querynum(int x){
		return query(root,1,n,x).first;
	}
};

void solve(){
	int n;
	cin>>n;
	int lastans=0;
	lichaoTree <long double> seg(mod);
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		if(op==0){
			int k;
			cin>>k;
			int x=(k+lastans-1)%mod+1;
			int ans=seg.queryid(x);
			cout<<ans<<'\n';
			lastans=ans;
		}
		else{
			int xa,ya,xb,yb;
			cin>>xa>>ya>>xb>>yb;
			xa=(xa+lastans-1)%mod+1;
			ya=(ya+lastans-1)%mod1+1;
			xb=(xb+lastans-1)%mod+1;
			yb=(yb+lastans-1)%mod1+1;
			if(xa>xb){
				swap(xa,xb);
				swap(ya,yb);
			} 
			seg.add(xa,ya,xb,yb);
		}
	}
	// seg.print();
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

/*
6 
1 8 5 10 8 
1 6 7 2 6 
0 2 
0 9 
1 4 7 6 7 
0 5



*/