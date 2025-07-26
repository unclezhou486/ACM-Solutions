#include <bits/stdc++.h>

using namespace std;

struct node{
	int pre=0,suf=0;
	vector<int> vec1={};
	string vec2;
	bool flag=false;
	node operator+(const node &b) const{
		node c;
		c.flag=flag|b.flag;
		if(c.flag){
			return c;
		}
		else{
			if(vec2.size()==0 && b.vec2.size()==0){
				c.pre=c.suf=(suf+b.pre);
			}
			else if(vec2.size()==0){
				c.vec2=b.vec2;
				c.vec1=b.vec1;
				c.pre=pre+b.pre;
				c.suf=b.suf;
			}
			else if(b.vec2.size()==0){
				c.vec2=vec2;
				c.vec1=vec1;
				c.pre=pre;
				c.suf=suf+b.suf;
			}
			else{
				if(vec2.size()+b.vec2.size()>12){
					c.flag=true;
					return c;
				}
				c=*this;
				c.vec1.push_back(suf+b.pre);
				c.suf=b.suf;
				for(auto x:b.vec1) c.vec1.push_back(x);
				for(auto x:b.vec2) c.vec2.push_back(x);
			}
			return c;
		}
	}
	void rev(){
		swap(pre,suf);
		reverse(vec1.begin(),vec1.end());
		reverse(vec2.begin(),vec2.end());
	}
};

node newnode(int k){
	node res;
	if(k==1){
		res.pre=res.suf=1;
		res.vec1={};
		res.vec2="";
		res.flag=false;
	}
	else if(k<=24){
		res.pre=res.suf=0;
		res.vec1={};
		res.vec2.push_back(k);
		res.flag=false;
	}
	else{
		res.flag=true;
	}
	return res;
}

struct segmentTree{
	int n;
	vector<node> num;
	void init(int n){
		this->n=n;
		num.assign(n<<2,{});
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
		if(mid<x) modify(rt<<1|1,x,mid+1,r,k);
		pushup(rt);
	}
	void modify(int x,int k){
		modify(1,x,1,n,k);
	}
	node query(int rt,int x,int y,int l,int r){
		if(x<=l&&r<=y){
			return num[rt];
		}
		int mid=(l+r)>>1;
		node res;
		if(x<=mid) res=query(rt<<1,x,y,l,mid);
		if(mid<y) res=res+query(rt<<1|1,x,y,mid+1,r);
		return res;
	}
	node query(int x,int y){
		return query(1,x,y,1,n);
	}
}seg;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n+10);
	vector<vector<int> > adj(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> dep(n+10),f(n+10),top(n+10),dfn(n+10),siz(n+10),son(n+10,-1);
	int tot=0;
	auto dfs1=[&](auto self,int x,int fa) -> void{
		dep[x]=dep[fa]+1;
		f[x]=fa;
		siz[x]=1;
		for(auto y:adj[x]){
			if(y==fa) continue;
			self(self,y,x);
			if(son[x]==-1||siz[son[x]]<siz[y]){
				son[x]=y;
			}
			siz[x]+=siz[y];
		}
	};
	auto dfs2=[&](auto self,int x,int tp) -> void{
		dfn[x]=++tot;
		top[x]=tp;
		if(son[x]!=-1) self(self,son[x],tp);
		for(auto y:adj[x]){
			if(y==f[x]||y==son[x]) continue;
			self(self,y,y);
		}
	};
	auto lca=[&](int x,int y) -> pair<node,node>{
		// if(top[x]==top[y])
		node resx,resy;
		while(x!=y){
			if(resx.flag|resy.flag) break;
			if(top[x]==top[y]){
				if(dep[x]>dep[y]){
					resx=seg.query(dfn[y]+1,dfn[x])+resx;
					x=y;
				}
				else{
					resy=seg.query(dfn[x]+1,dfn[y])+resy;
					y=x;
				}
			}
			else{
				if(dep[top[x]]>dep[top[y]]){
					resx=seg.query(dfn[top[x]],dfn[x])+resx;
					x=f[top[x]];
				}
				else{
					resy=seg.query(dfn[top[y]],dfn[y])+resy;
					y=f[top[y]];
				}
			}
		}
		resy=newnode(a[x])+resy;
		return {resx,resy};
	};
	dfs1(dfs1,1,1);
	dfs2(dfs2,1,1);
    seg.init(n);
	for(int i=1;i<=n;i++){
		seg.modify(dfn[i],a[i]);
	}
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int l,r;
			cin>>l>>r;
			if(l==r){
				if(a[l]==24){
					cout<<"1\n";
				}
				else{
					cout<<"0\n";
				}
				continue;
			}
			if(a[l]>24){
				cout<<"0\n";
				continue;
			}
			auto [resx,resy]=lca(l,r);
			resx.rev();
			node res=resx+resy;
			if(res.flag){
				cout<<0<<'\n';
			}
			else{
				vector<int> vec1,vec2;
				vec1.push_back(res.pre);
				for(auto x:res.vec1) vec1.push_back(x);
				for(auto x:res.vec2) vec2.push_back(x);
				if(vec2.size())vec1.push_back(res.suf);
				bitset<25> dp;
				// dp[a[l]]=1;
				int id=0;
				if(vec1.size()&&vec1[0]==0){
					dp[vec2[0]]=1;
					id+=1;
				}
				else{
					dp[1]=1;
					vec1[0]-=1;
				}
				for(int i=id;i<vec2.size();i++){
					int cnt1=vec1[i];
					for(int j=1;j<=min(cnt1,24);j++){
						dp|=(dp<<1);
					}
					int num=vec2[i];
					// bitset<25> dpp;
					for(int i=24;i>=0;i--){
						int res1=0,res2=0;
						if(i%num==0) res1=dp[i/num];
						if(i-num>=0) res2=dp[i-num];
						// if(i%num==0){
						dp[i]=res1|res2;
						// }
					}
					// dp=dpp;
				}
				for(int j=1;j<=min(vec1.back(),24);j++){
					dp|=dp<<1;
				}
				if(dp[24]) cout<<"1\n";
				else cout<<"0\n";
			}
		}
		else{
			int x,d;
			cin>>x>>d;
			a[x]=d;
			seg.modify(dfn[x],d);
		}
	}
}

int main(){
	// freopen("1.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}