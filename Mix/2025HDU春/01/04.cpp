#include <bits/stdc++.h>

using namespace std;

constexpr int mod=1e9+7;

constexpr int N=1e5+10;

struct node{
	int x,y,id;
	// cin>>x>>y;
	bool operator<(const node &a){
		return y<a.y;
	}
};

int a[N];
int Maxx0[N][20];
int Maxx1[N][20];
int Minx1[N][20];
int Minx0[N][20];
int tor[N];
int tol[N][20];

bool check(int l,int r){
	if(l==r) return 1;
		else if(l+1==r) return a[l]!=a[r];
		int ll,rr;
		if(r%2!=l%2){
			rr=r;
			ll=l+1;
			l=l;
			r=r-1;
		}
		else{
			rr=r;
			ll=l;
			l=l+1;
			r=r-1;
		}
        if(rr%2==0){
            swap(r,rr);
            swap(l,ll);
        }
		int t=floor(log2(r-l+1))-1;
        if(l==r) t=0;
		int tt=floor(log2(rr-ll+1))-1;
        if(ll==rr) tt=0;
		int max1=max(Maxx1[ll][tt],Maxx1[rr-(1<<(tt+1))+2][tt]);
		int min1=min(Minx0[l][t],Minx0[r-(1<<(t+1))+2][t]);
		int max2=max(Maxx0[l][t],Maxx0[r-(1<<(t+1))+2][t]);
		int min2=min(Minx1[ll][tt],Minx1[rr-(1<<(tt+1))+2][tt]);
		if(max1<min1||max2<min2){
			return 1;
		}
		else{
			return 0;
		}
}

int queryx (int l,int r){
	int t=floor(log2(r-l+1));
	return max(tol[r][t],tol[l+(1<<t)-1][t]);
};

void solve(){
	int n,q;
	cin>>n>>q;
	// vector<int> a(n+10);
	// vector<vector<int> > Maxx0(n+10,vector<int>(20,-2e9));
	// vector<vector<int> > Maxx1(n+10,vector<int>(20,-2e9));
	// vector<vector<int> > Minx0(n+10,vector<int>(20,2e9));
	// vector<vector<int> > Minx1(n+10,vector<int>(20,2e9));
	// vector<vector<int> > to(n+10,vector<int>(20) ) ;
	// for(int i=0;i<n+10;i++){
	// 	for(int j=0;j<20;j++){
	// 		Maxx0[i][j]=-2e9;
	// 		Maxx1[i][j]=-2e9;
	// 		Minx0[i][j]=2e9;
	// 		Minx1[i][j]=2e9;
	// 		// to[i][j]=0;
	// 	}
	// }
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i%2){
			Maxx1[i][0]=a[i];
			Minx1[i][0]=a[i];
		}
		else{
			Maxx0[i][0]=a[i];
			Minx0[i][0]=a[i];
		}
	}
	for(int i=1;i<20;i++){
		int pi=(1<<(i));
		for(int j=1;j+pi<=n;j++){
			// to[j][i]=to[to[j][i-1]][i-1];
			Maxx1[j][i]=max(Maxx1[j][i-1],Maxx1[j+pi][i-1]);
			Maxx0[j][i]=max(Maxx0[j][i-1],Maxx0[j+pi][i-1]);
			Minx1[j][i]=min(Minx1[j][i-1],Minx1[j+pi][i-1]);
			Minx0[j][i]=min(Minx0[j][i-1],Minx0[j+pi][i-1]);
		}
	}
	// auto check = [&] (int l,int r) -> bool {
	// 	if(l==r) return 1;
	// 	else if(l+1==r) return a[l]!=a[r];
	// 	int ll,rr;
	// 	if(r%2!=l%2){
	// 		rr=r;
	// 		ll=l+1;
	// 		l=l;
	// 		r=r-1;
	// 	}
	// 	else{
	// 		rr=r;
	// 		ll=l;
	// 		l=l+1;
	// 		r=r-1;
	// 	}
    //     if(rr%2==0){
    //         swap(r,rr);
    //         swap(l,ll);
    //     }
	// 	int t=floor(log2(r-l+1))-1;
	// 	int tt=floor(log2(rr-ll+1))-1;
	// 	int max1=max(Maxx1[ll][tt],Maxx1[rr-(1<<(tt+1))+2][tt]);
	// 	int min1=min(Minx0[l][t],Minx0[r-(1<<(t+1))+2][t]);
	// 	int max2=max(Maxx0[l][t],Maxx0[r-(1<<(t+1))+2][t]);
	// 	int min2=min(Minx1[ll][tt],Minx1[rr-(1<<(tt+1))+2][tt]);
	// 	if(max1<min1||max2<min2){
	// 		return 1;
	// 	}
	// 	else{
	// 		return 0;
	// 	}
	// };
	vector<pair<int,int> > vec;
	// vector<int> tor(n+10);
	// vector<vector<int> > tol(n+10,vector<int>(20));
	int j=1;
	for(int i=1;i<=n;i++){
		for(;!check(j,i);j++)tor[j]=i-1;
		tor[j]=i;
		tol[i][0]=(i-j+1);
		// int l=1,r=i;
		// while(l<r){
		// 	int mid=(l+r)>>1;
		// 	if(check(mid,i)) r=mid;
		// 	else l=mid+1;
		// }
		// tol[i][0]=(i-l+1);
		// l=i,r=n;
		// while(l<r){
		// 	int mid=(l+r+1)>>1;
		// 	if(check(i,mid)) l=mid;
		// 	else r=mid-1; 
		// }
		// tor[i]=l;
		// cout<<tor[i]<<" \n"[i==n];
		// cout<<tol[i][0]<<" \n"[i==n];
	}
	for(int i=j+1;i<=n;i++){
		tor[i]=n;
	}
	// for(int i=1;i<=n;i++){
		// cout<<tor[i]<<" \n"[i==n];
	// }
	for(int i=1;i<20;i++){
		int pi=(1<<(i-1));
		for(int j=n;j-pi>=1;j--){
			tol[j][i]=max(tol[j][i-1],tol[j-pi][i-1]);
		}
	}
	// auto queryx = [&] (int l,int r) -> int {
	// 	int t=floor(log2(r-l+1));
	// 	return max(tol[l][t],tol[r-(1<<t)+1][t]);
	// };
	int ans=0;
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		int res=(min(tor[l],r)-l+1);
		if(tor[l]+1<=r) res=max(res,queryx(tor[l]+1,r));
		ans=(ans+1ll*res*i)%mod;
	}
	cout<<ans<<'\n';

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