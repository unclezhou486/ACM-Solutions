#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	long long k;
	cin>>n>>k;
	vector<int> a(n+10),l1(n+10),r1(n+10);
	vector<vector<int> > maxn(n+10,vector<int>(20)),to(n+10,vector<int>(20));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		to[i][0]=i+1;
		maxn[i][0]=a[i];
	}
	stack<pair<int,int> > st;
	st.push({-1,0});
	for(int i=1;i<=n;i++){
		while(st.top().first>=a[i]) st.pop();
		l1[i]=st.top().second+1;
		st.push({a[i],i});
	}
	while(st.size()) st.pop();
	st.push({-1,n+1});
	for(int i=n;i>=1;i--){
		while(st.top().first>a[i]) st.pop();
		r1[i]=st.top().second-1;
		st.push({a[i],i});
	}
	// for(int i=1;i<=n;i++) cout<<l1[i]<<" \n"[i==n];
	// for(int i=1;i<=n;i++) cout<<r1[i]<<" \n"[i==n];
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			to[j][i]=to[to[j][i-1]][i-1];
			maxn[j][i]=max(maxn[j][i-1],maxn[to[j][i-1]][i-1]);
		}
	}
	auto query = [&](int l,int r) -> int {
		int len=(r-l+1);
		int t=floor(log2(len));	
		return max(maxn[l][t],maxn[r-(1<<t)+1][t]);
	};

	auto check = [&] (int x) -> bool{
		long long cnt=0;
		for(int i=1;i<=n;i++){
			int res=x-a[i];
			cnt+=1ll*(r1[i]-i+1)*(i-l1[i]+1);
			if(res<=a[i]) continue; 
			int L=l1[i],R=i;
			int l0,r0;
			while(L<R){
				int mid=(L+R)>>1;
				if(query(mid,i)>=res) L=mid+1;
				else R=mid;
			}
			l0=L;
			L=i,R=r1[i];
			while(L<R){
				int mid=(L+R+1)>>1;
				if(query(i,mid)>=res) R=mid-1;
				else L=mid;
			}
			r0=L;
			cnt-=1ll*(r0-i+1)*(i-l0+1);
		}
		if(cnt>=k) return 1;
		else return 0;
	};

	int l=0,r=2e9;
	while(l<r){
		int mid=(1ll*l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<'\n';
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
