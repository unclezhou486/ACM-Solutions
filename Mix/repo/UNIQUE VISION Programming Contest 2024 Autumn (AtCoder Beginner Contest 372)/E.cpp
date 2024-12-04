#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N=2e5+10;

int n,f[N],q;

int ans[N][14];

int b[30];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}


void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) f[i]=i,ans[i][1]=i;
	while(q--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			if(find(x)==find(y)) continue;
			else{
				int xx=find(x),yy=find(y);
				int ql=1,qr=1;
				for(int i=1;i<=10;i++){
					if((ql<=10&&ans[xx][ql]>ans[yy][qr])||qr>10){
						b[i]=ans[xx][ql];
						ql++;
					}
					else{
						b[i]=ans[yy][qr];
						qr++;
					}
				}
				for(int i=1;i<=10;i++){
					ans[yy][i]=b[i];
				}
				f[find(x)]=find(y);
			}
		}
		else{
			int anss=ans[find(x)][y];
			if(!anss){
				cout<<-1<<'\n';
			}
			else cout<<anss<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}