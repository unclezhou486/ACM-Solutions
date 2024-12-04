#include <bits/stdc++.h>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int lowbit(int x){return x&-x;}

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int> > a(n+10,vector<int>(m+10,0)),pre1(n+10,vector<int>(m+10,0)),pre2(n+10,vector<int>(m+10,0));
	auto add = [&] (int x,int y,int val) -> void{
		int xx,yy;
		xx=x,yy=y;
		for(;yy<=m;yy+=lowbit(yy)) pre1[x][yy]+=val;
		xx=x,yy=y;
		for(;xx<=n;xx+=lowbit(xx)) pre2[xx][y]+=val;

	};
	auto get_linep = [&](int x,int y) ->int{
		int res=0;
		for(;y;y-=lowbit(y)){
			res+=pre1[x][y];
		}
		return res;
	}; 
	auto get_line = [&](int x,int l,int r) ->int {
		return get_linep(x,r)-get_linep(x,l-1);
	};
	auto get_rowp = [&](int x,int y) ->int{
		int res=0;
		for(;x;x-=lowbit(x)){
			res+=pre2[x][y];
		}
		return res;
	};
	auto get_row = [&](int y,int l,int r) ->int{
		return get_rowp(r,y)-get_rowp(l-1,y);
	};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=1;
			add(i,j,1);
		}
	}
	int cnt=0;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(a[x][y]){
			a[x][y]=0;
			cnt+=1;
			add(x,y,-1);
		}
		else{
			int l,r;
			l=1,r=x-1;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(get_row(y,mid,x-1)) l=mid;
				else r=mid-1;
			}
			if(a[l][y]){
				a[l][y]=0;
				cnt+=1;
				add(l,y,-1);
			}
			l=x+1,r=n;
			while(l<r){
				int mid=(l+r)>>1;
				if(get_row(y,x+1,mid)) r=mid;
				else l=mid+1;
			}
			if(a[l][y]){
				a[l][y]=0;
				cnt+=1;
				add(l,y,-1);
			}
			l=1,r=y-1;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(get_line(x,mid,y-1)) l=mid;
				else r=mid-1;
			}
			if(a[x][l]){
				a[x][l]=0;
				cnt+=1;
				add(x,l,-1);
			}
			l=y+1,r=m;
			while(l<r){
				int mid=(l+r)>>1;
				if(get_line(x,y+1,mid)) r=mid;
				else l=mid+1;
			}
			if(a[x][l]){
				a[x][l]=0;
				cnt+=1;
				add(x,l,-1);
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		cout<<a[i][j]<<" \n"[j==m];
	// 	}
	// }
	cout<<n*m-cnt<<'\n';
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