#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=2e5+10;

long long a[500][500];
int n,m,q,k;
struct node{
	int x,y;
	long long t;
}b[N];

int c[10];

void solve(){
	cin>>n>>m;
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		long long t;
		cin>>x>>y>>t;
		b[i]={x,y,t};
		a[x][y]=a[y][x]=min(a[x][y],t);
	}
	b[0]={1,1,0};
	b[m+1]={n,n,0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
			}
		}
	}

	cin>>q;
	while(q--){
		cin>>k;
		for(int i=1;i<=k;i++) cin>>c[i];
		c[0]=0;
		c[k+1]=m+1;
		long long ans=1e18;
		do{
			for(int bit=0;bit<(1<<k);bit++){
				for(int i=1;i<=k;i++){
					if((bit>>(i-1))&1){
						swap(b[c[i]].x,b[c[i]].y);
					}
				}
				long long res=0;
				for(int i=1;i<=k+1;i++){
					res+=a[b[c[i-1]].y][b[c[i]].x];
					res+=b[c[i]].t;
				}
				ans=min(ans,res);	
				for(int i=1;i<=k;i++){
					if((bit>>(i-1))&1){
						swap(b[c[i]].x,b[c[i]].y);
					}
				}
			}
		}while(next_permutation(c+1,c+1+k));
		cout<<ans<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}