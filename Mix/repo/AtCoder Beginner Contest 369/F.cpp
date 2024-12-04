#include <bits/stdc++.h>

using namespace std;

constexpr int N=2e5+200;

int n,h,w;

struct node{
	int x,y;
	bool operator< (const node &a){
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
}a[N];

int dp[N];

struct BIT{
	int b[N];
	int n;
	void init(int n){
		this->n=n;
		memset(b,0,sizeof b);
	}
	int lowbit(int x){return x&-x;}
	void add(int k,int x){k+=1;for(;k<=n;k+=lowbit(k)) b[k]=max(x,b[k]);}
	int query(int x){
		int res=0;
		x+=1;
		for(;x;x-=lowbit(x)){
			res=max(res,b[x]);
		}
		return res;
	}
}bit;

void solve(){
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	a[0].x=1,a[0].y=1;
	a[n+1].x=h,a[n+1].y=w;
	sort(a+1,a+2+n);
	dp[0]=1;
	bit.init(w+10);
	bit.add(1,1);
	// for(int i=1;i<=n+1;i++){
		// cout<<a[i].x<<' '<<a[i].y<<'\n';
	// }
	for(int i=1;i<=n+1;i++){
		dp[i]=bit.query(a[i].y)+1;
		// cout<<dp[i]<<" \n"[i==n+1];
		bit.add(a[i].y,dp[i]);
	}
	cout<<dp[n+1]-2<<'\n';
	stack<node> st;
	vector<node> vec;
	st.push(a[n+1]);
	int x=n+1;
	for(int i=n;i>=0;i--){
		if(a[i].x<=a[x].x&&a[i].y<=a[x].y&&dp[i]==dp[x]-1){
			x=i;
			st.push(a[x]);
		}
	}
	while(st.size()){
		vec.push_back(st.top());
		st.pop();
		// cout<<st.top().x<<' '<<st.top().y<<'\n',st.pop();
	} 
	for(int i=1;i<vec.size();i++){
		int x=vec[i].x-vec[i-1].x;
		int y=vec[i].y-vec[i-1].y;
		for(int j=1;j<=x;j++){
			cout<<'D';
		}
		for(int j=1;j<=y;j++){
			cout<<"R";
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