#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=2e5+10;

int st1[N][20],st2[N][20];

int n;
int a[N];

int x,y;

int get_min(int l,int r){
	int len=(r-l+1);
	int q=floor(log2(len));
	return min(st1[l][q],st1[r-(1<<q)+1][q]);
}

int get_max(int l,int r){
	int len=(r-l+1);
	int q=floor(log2(len));
	return max(st2[l][q],st2[r-(1<<q)+1][q]);

}

void solve(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st1[i][0]=st2[i][0]=a[i];
	}
	for(int i=1;i<20;i++){
		for(int j=1;j+(1<<(i-1))<=n;j++){
			st1[j][i]=min(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
			st2[j][i]=max(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(get_min(i,mid)>y) l=mid+1;
			else r=mid;
		}
		int minl=l;
		if(get_min(i,minl)!=y) continue;
		l=minl,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(get_min(i,mid)<y) r=mid-1;
			else l=mid;
		}
		int minr=l;
		l=minl,r=minr;
		while(l<r){
			int mid=(l+r)>>1;
			if(get_max(i,mid)<x) l=mid+1;
			else r=mid;
		}
		int maxl=l;
		if(get_max(i,maxl)!=x) continue;
		l=maxl,r=minr;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(get_max(i,mid)>x) r=mid-1;
			else l=mid;
		}
		int maxr=r;
		ans+=(maxr-maxl+1);
	}

	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}