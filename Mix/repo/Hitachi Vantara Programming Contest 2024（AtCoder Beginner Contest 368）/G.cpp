#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

long long pre[N];
long long a[N];
long long b[N];
int q;
int n;

struct BIT{
	long long a[N];
	int n;
	void init(int n){
		this->n=n;
		memset(a,0,sizeof a);
	}
	int lowbit(int x){
		return x&-x;
	}
	void add(int k,long long x){
		for(;k<=n;k+=lowbit(k)){
			a[k]+=x;
		}
	}
	long long query(int x){
		long long res=0;
		for(;x;x-=lowbit(x)){
			res+=a[x];
		}
		return res;
	}
	long long query(int l,int r){
		return query(r)-query(l-1);
	}
}bita,bitb;

void solve(){
	cin>>n;
	bita.init(n),bitb.init(n);
	for(int i=1;i<=n;i++) cin>>a[i],bita.add(i,a[i]);
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]>1){
			bitb.add(i,1);
		}
	}
	cin>>q;
	while(q--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			bita.add(x,-a[x]);
			a[x]=y;
			bita.add(x,a[x]);
		}
		else if(op==2){
			if(b[x]>1) bitb.add(x,-1);
			b[x]=y;
			if(b[x]>1) bitb.add(x,1);
		}
		else{
			long long ans=0;
			ans+=a[x];
			x+=1;
			while(x<=y){
				int l=x,r=y;
				while(l<r){
					int mid=(l+r)>>1;
					if(bitb.query(x,mid)) r=mid;
					else l=mid+1;
				}
				ans+=bita.query(x,l-1);
				ans=max({ans,ans+a[l],ans*b[l]});
				x=l+1;
			}
			cout<<ans<<'\n';
		}
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