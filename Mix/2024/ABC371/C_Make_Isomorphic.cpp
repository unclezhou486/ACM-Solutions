#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int N=10;

int p[N];

int n;
int mg,mh;

bool v1[N][N],v2[N][N],v3[N][N];

int a[N][N];


void solve(){
	cin>>n;
	cin>>mg;
	for(int i=1;i<=mg;i++){
		int x,y;
		cin>>x>>y;
		// adj1[i]={x,y};
		v1[x][y]=1;
	}
	cin>>mh;
	for(int i=1;i<=mh;i++){
		int x,y;
		cin>>x>>y;
		v2[x][y]=1;
		// adj2[i]={x,y};
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	int ans=1e9;
	do{
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x,y;
				x=p[i],y=p[j];
				if(x>y) swap(x,y);
				if(v1[i][j]&&!v2[x][y]){
					res+=a[x][y];
				}
				else if(!v1[i][j]&&v2[x][y]){
					res+=a[x][y];
				}
			}
		}
		ans=min(ans,res);
	}while(next_permutation(p+1,p+1+n));
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