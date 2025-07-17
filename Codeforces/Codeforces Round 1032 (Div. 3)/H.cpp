#include <bits/stdc++.h>


using namespace std;

constexpr int maxn=1e9;
constexpr int nodecnt=100;
struct seg{
	int tot,root;
	vector<int> cnt,ls,rs,lz,lzmax;
	void init(int n){
		root=tot=0;
		cnt.assign(n*nodecnt,{});
		ls.assign(n*nodecnt,{});
		rs.assign(n*nodecnt,{});
		lz.assign(n*nodecnt,{});
		lzmax.assign(n*nodecnt,{});
	}
	void pushdown(int rt){
		if(lz[rt]){
			if(!ls[rt]) ls[rt]=++tot;
			if(!rs[rt]) rs[rt]=++tot;
			cnt[ls[rt]]+=lz[rt];
			cnt[rs[rt]]+=lz[rt];
            lzmax[ls[rt]]+=lz[rt];
            lzmax[rs[rt]]+=lz[rt];
			lz[ls[rt]]+=lz[rt];
			lz[rs[rt]]+=lz[rt];
			lz[rt]=0;
		}
		if(lzmax[rt]){
			if(!ls[rt]) ls[rt]=++tot;
			if(!rs[rt]) rs[rt]=++tot;
			cnt[ls[rt]]=max(cnt[ls[rt]],lzmax[rt]);
			cnt[rs[rt]]=max(cnt[rs[rt]],lzmax[rt]);
			lzmax[ls[rt]]=max(lzmax[rt],lzmax[ls[rt]]);
			lzmax[rs[rt]]=max(lzmax[rt],lzmax[rs[rt]]);
			lzmax[rt]=0;
		}
	}
	void update(int x,int y,int l,int r,int &rt,int k){
		if(!rt){
			rt=++tot;
		}
		if(x<=l&&r<=y){
			cnt[rt]+=k;
			lz[rt]+=k;
			lzmax[rt]+=k;
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if(x<=mid) update(x,y,l,mid,ls[rt],k);
		if(mid<y) update(x,y,mid+1,r,rs[rt],k);
		cnt[rt]=max(cnt[ls[rt]],cnt[rs[rt]]);
	}
	void updatemax(int x,int y,int l,int r,int &rt,int k){
		if(!rt){
			rt=++tot;
		}
		if(x<=l&&r<=y){
			cnt[rt]=max(k,cnt[rt]);
			lzmax[rt]=max(k,lzmax[rt]);
			return;
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		if(x<=mid) updatemax(x,y,l,mid,ls[rt],k);
		if(mid<y) updatemax(x,y,mid+1,r,rs[rt],k);
		cnt[rt]=max(cnt[ls[rt]],cnt[rs[rt]]);
	}
	void update(int x,int y,int k){
		update(x,y,0,maxn,root,k);
	}
	void updatemax(int x,int y,int k){
		updatemax(x,y,0,maxn,root,k);
	}
	int query(int x,int l,int r,int &rt){
		if(!rt) return 0;
		if(l==r){
			return cnt[rt];
		}
		pushdown(rt);
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid) res=max(res,query(x,l,mid,ls[rt]));
		if(mid<x) res=max(res,query(x,mid+1,r,rs[rt]));
		return res; 
	}
	int query(int x){
		return query(x,0,maxn,root);
	}
	int getroot(){
		return cnt[root];
	}
}seg;

void solve(){
	int n;
	cin>>n;
	seg.init(n+10);
	int len=0;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		seg.update(a,b,1);
		int rescnt=seg.query(b);
		seg.updatemax(b,maxn,rescnt);
		cout<<seg.getroot()<<" \n"[i==n];
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
