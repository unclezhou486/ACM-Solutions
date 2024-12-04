#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	string str;
	vector<int> l(n+10),r(n+10),s(n+10);
	vector<vector<int> > ne(n+10,vector<int>(20)),pe(n+10,vector<int>(20) );
	vector<int> a(n+10);
	cin>>str;
	for(int i=0;i<n;i++){
		if(str[i]=='1') a[i+1]=1;
		else if(str[i]=='2') a[i+1]=2;
		else a[i+1]=3,s[i+1]=1;
	}
	r[n+1]=n+1;
	l[0]=0;
	for(int i=n;i>=0;i--){
		if(a[i]==1) r[i]=i;
		else r[i]=r[i+1];
	}
	for(int i=1;i<=n+1;i++){
		s[i]+=s[i-1];
		if(a[i]==2){
			l[i]=i;
		}
		else l[i]=l[i-1];
	}
	// for(int i=0;i<=n+1;i++){
	// 	cout<<l[i]<<" \n"[i==n+1];
	// }
	// for(int i=0;i<=n+1;i++){
	// 	cout<<r[i]<<" \n"[i==n+1];
	// }
	for(int i=0;i<=n+1;i++){
		if(i&&l[i]==i) pe[i][0]=l[i-1];
		else pe[i][0]=l[i];
		for(int j=1;j<20;j++){
			pe[i][j]=pe[pe[i][j-1]][j-1];
		}
	}
	for(int i=n+1;i>=0;i--){
		if(i!=n+1&&r[i]==i) ne[i][0]=r[i+1];
		else ne[i][0]=r[i];
		for(int j=1;j<20;j++){
			ne[i][j]=ne[ne[i][j-1]][j-1];
		}
	}
	for(int j=0;j<20;j++){
		ne[n+1][j]=n+1;
		pe[0][j]=0;
	}
	auto to_next = [&](int st,int len) -> int {
		for(int i=0;i<20;i++){
			if((len>>i)&1) st=ne[st][i];
		}
		return st;
	};
	auto to_prev = [&](int st,int len) -> int {
		for(int i=0;i<20;i++){
			if((len>>i)&1) st=pe[st][i];
		}
		return st;
	};
	auto check = [&](int l,int r,int x) -> bool {
		int id1=to_next(l-1,x),id2=to_prev(r+1,x);
		int has3=s[id2-1]-s[id1];
		// cout<<l<<' '<<r<<' '<<x<<' '<<id1<<' '<<id2<<'\n';
		if(id1<id2&&has3){
			return 1;
		}
		return 0;
	};
	while(q--){
		int l,r;
		cin>>l>>r;
		int L=0,R=(r-l+1);
		while(L<R){
			int mid=(L+R+1)>>1;
			if(check(l,r,mid)) L=mid;
			else R=mid-1;
		}

		int ans=0;
		ans+=L*2;
		if(s[r]-s[l-1]) ans+=1;
		cout<<ans<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}