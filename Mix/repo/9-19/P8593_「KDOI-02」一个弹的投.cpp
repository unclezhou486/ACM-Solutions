#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <cstring>
#include <queue>


using namespace std;

const int N=5e5+10;

int n,m;

int xx[N],yy[N],vv[N];
double ww[N];
int d[N];

struct no{
	double d;
	int id;
}c[N];

struct node{
	long long x,d;
	int id;
};

bool cmp(node a,node b){
	return a.x<b.x;
}

bool cmp1(no a,no b){
	return a.d<b.d;
}

int a[N];
map<int,vector<node> > ma;

struct BIT{
	int n;
	int bit[N];
	void init(int n){
		memset(bit,0,sizeof bit);
		this->n=n;
	}
	int lowbit(int x){
		return x&-x;
	}
	void add(int k,int x){
		for(;k<=n;k+=lowbit(k)) bit[k]+=x;
	}
	int query(int x){
		int res=0;
		for(;x;x-=lowbit(x)){
			res+=bit[x];
		}
		return res;
	}
}bit;

int ans[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>xx[i]>>yy[i]>>vv[i];
		ww[i]=1.0*vv[i]*sqrt(2.0*yy[i]/9.8)+1.0*xx[i];
		c[i]={ww[i],i};
	}
	sort(c+1,c+1+n,cmp1);
	int cnt=0;
	d[c[1].id]=++cnt;
	for(int i=2;i<=n;i++){
		if(c[i].d==c[i-1].d){
			d[c[i].id]=cnt;
		}
		else{
			d[c[i].id]=++cnt;
		}
	}
	for(int i=1;i<=n;i++){
		node pos={xx[i],d[i],i};
		ma[yy[i]].push_back(pos);
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	bit.init(n);
	for(auto [y,vec]:ma){
		sort(vec.begin(),vec.end(),cmp);
		for(auto [x,d,id]:vec){
			ans[id]=bit.query(n)-bit.query(d-1);
			bit.add(d,1);
		}
		for(auto [x,d,id]:vec){
			bit.add(d,-1);
		}
		reverse(vec.begin(),vec.end());
		for(auto [x,d,id]:vec){
			ans[id]+=bit.query(d);
			bit.add(d,1);
		} 
		for(auto [x,d,id]:vec){
			bit.add(d,-1);
		}
	}
	long long anss=0;
	priority_queue<int> qu;
	for(int i=1;i<=n;i++){
		anss+=ans[i];
		qu.push(min(a[i],ans[i]));
	}
	while(m--){
		anss-=qu.top();
		qu.pop();
	}
	cout<<anss<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

/*

1/2 g t^2=y
t=(2y/g)^0.5

d=x+vt=x+v*(2y/g)^0.5

*/