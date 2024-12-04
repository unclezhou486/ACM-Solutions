#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
const int mod=998244353;

int n,nn;

struct node{
	int ls,rs;
	int sum;
};

struct seg{
	int tot=0;
	int root[N<<1];
	node tr[N*22];
	void add(int &rt,int k,int x,int l,int r){
		if(!rt) rt=++tot;
		tr[rt].sum+=x;
		if(tr[rt].sum>=mod)tr[rt].sum%=mod;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(k<=mid) add(tr[rt].ls,k,x,l,mid);
		if(mid<k) add(tr[rt].rs,k,x,mid+1,r);
	}
	void add(int rt,int k,int x){
		add(root[rt],k,x,0,nn);
	}
	int query(int rt,int x,int y,int l,int r){
		if(x<=l&&r<=y){
			return tr[rt].sum;
		}
		if(!rt) return 0;
		int res=0;
		int mid=(l+r)>>1;
		if(x<=mid) res+=query(tr[rt].ls,x,y,l,mid);
		if(mid<y) res+=query(tr[rt].rs,x,y,mid+1,r);
		return res%mod;
	}
	int query(int rt,int x,int y){
		return query(root[rt],x,y,0,nn);
	}
}a[3];

string str;

int pre[3];

void solve(){
	cin>>str;
	n=str.size();
	nn=n<<1;
	str="#"+str;
	int ans=0;
	a[0].add(n,n,1);
	a[1].add(n,n,1);
	a[2].add(n,n,1);
	for(int i=1;i<=n;i++){
		if(str[i]=='I') pre[0]+=1;
		else if(str[i]=='C') pre[1]+=1;
		else if(str[i]=='P') pre[2]+=1;
		ans=0;
		ans+=a[0].query(pre[0]-pre[1]+n,pre[0]-pre[2]+n+1,nn);
		ans%=mod;
		ans+=a[1].query(pre[0]-pre[2]+n,pre[0]-pre[1]+n+1,nn);
		ans%=mod;
		ans+=a[2].query(pre[1]-pre[2]+n,pre[1]-pre[0]+n+1,nn);
		ans%=mod;
		a[0].add(pre[0]-pre[1]+n,pre[0]-pre[2]+n,ans);
		a[1].add(pre[0]-pre[2]+n,pre[0]-pre[1]+n,ans);
		a[2].add(pre[1]-pre[2]+n,pre[1]-pre[0]+n,ans);
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}