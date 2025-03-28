#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int maxn=1e9;

struct seg{
	vector<int> num[4],ls,rs;
	int tot;
	void init(int n){
		tot=0;
		num[0].assign(n*40,-2e9);
		num[1].assign(n*40,-2e9);
		num[2].assign(n*40,-2e9);
		num[3].assign(n*40,-2e9);
		ls.assign(n*40,{});
		rs.assign(n*40,{});
	}
	void update(int k,int l,int r,int x,int &rt){
		if(!rt){
			rt=++tot;
		}
		if(l==r){
			num[0][rt]=max(-x-l,num[0][rt]);
			num[1][rt]=max(l-x,num[1][rt]);
			num[2][rt]=max(x-l,num[2][rt]);
			num[3][rt]=max(x+l,num[3][rt]);
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid) update(k,l,mid,x,ls[rt]);
		if(mid<k) update(k,mid+1,r,x,rs[rt]);
		num[0][rt]=max(num[0][ls[rt]],num[0][rs[rt]]);
		num[1][rt]=max(num[1][ls[rt]],num[1][rs[rt]]);
		num[2][rt]=max(num[2][ls[rt]],num[2][rs[rt]]);
		num[3][rt]=max(num[3][ls[rt]],num[3][rs[rt]]);
	}
	int query0(int x,int y,int l,int r,int rt){
		if(!rt){
			return -2e9;
		}
		if(l<=x&&y<=r){
			return num[0][rt];
		}
		int mid=(x+y)>>1;
		int res=-2e9;
		if(l<=mid) res=max(res,query0(x,mid,l,r,ls[rt]));
		if(mid<r) res=max(res,query0(mid+1,y,l,r,rs[rt]));
		return res;
	}
	int query1(int x,int y,int l,int r,int rt){
		if(!rt){
			return -2e9;
		}
		if(l<=x&&y<=r){
			return num[1][rt];
		}
		int mid=(x+y)>>1;
		int res=-2e9;
		if(l<=mid) res=max(res,query1(x,mid,l,r,ls[rt]));
		if(mid<r) res=max(res,query1(mid+1,y,l,r,rs[rt]));
		return res;
	}
	int query2(int x,int y,int l,int r,int rt){
		if(!rt){
			return -2e9;
		}
		if(l<=x&&y<=r){
			return num[2][rt];
		}
		int mid=(x+y)>>1;
		int res=-2e9;
		if(l<=mid) res=max(res,query2(x,mid,l,r,ls[rt]));
		if(mid<r) res=max(res,query2(mid+1,y,l,r,rs[rt]));
		return res;
	}
	int query3(int x,int y,int l,int r,int rt){
		if(!rt){
			return -2e9;
		}
		if(l<=x&&y<=r){
			return num[3][rt];
		}
		int mid=(x+y)>>1;
		int res=-2e9;
		if(l<=mid) res=max(res,query3(x,mid,l,r,ls[rt]));
		if(mid<r) res=max(res,query3(mid+1,y,l,r,rs[rt]));
		return res;
	}	
}st;

struct node{
	int x,y;
	bool operator<(const node &a){
		return x<a.x;
	}
};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<node> a(n+10),b(m+10);
	vector<int> ans1(m+10),ans2(m+10);
	st.init(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].x>>b[i].y;
	}
	sort(a.begin()+1,a.begin()+1+n);
	sort(b.begin()+1,b.begin()+1+m);
	int ans=2e9;
	int id=1;
	int root=1;
	for(int i=1;i<=m;i++){
		while(id<=n&&a[id].x<=b[i].x){
			st.update(a[id].y,1,maxn,a[id].x,root);
			id+=1;
		}
		int res=st.query0(1,maxn,1,b[i].y,root);
		if(res!=-2e9) ans1[i]=max(b[i].x+b[i].y+res,ans1[i]);
		res=st.query1(1,maxn,b[i].y,maxn,root);
		if(res!=-2e9) ans1[i]=max(ans1[i],b[i].x-b[i].y+res);
		// ans=min(ans,min(b[i].x+b[i].y+st.query0(1,maxn,1,b[i].y,root),-b[i].x+b[i].y+st.query1(1,maxn,b[i].y,maxn,root)));
	}
	st.init(n+10);
	id=n;
	for(int i=m;i>=1;i--){
		while(id>=1&&a[id].x>=b[i].x){
			st.update(a[id].y,1,maxn,a[id].x,root);
			id-=1;
		}
		int res=st.query2(1,maxn,1,b[i].y,root);
		if(res!=-2e9) ans1[i]=max(ans1[i],b[i].y-b[i].x+res);
		res=st.query3(1,maxn,b[i].y,maxn,root);
		if(res!=-2e9) ans1[i]=max(ans1[i],-b[i].y-b[i].x+res);
		// ans=min(ans,min(b[i].x-b[i].y+st.query2(1,maxn,1,b[i].y,root),-b[i].y-b[i].x+st.query3(1,maxn,b[i].y,maxn,root)));
	}
	for(int i=1;i<=m;i++){
		ans=min(ans,ans1[i]);
	}
	cout<<ans<<'\n';
}

signed main(){
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
2 2
1 2
2 1
1 1
2 2
*/