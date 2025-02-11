#include <bits/stdc++.h>

using namespace std;

int xx[4],yy[4];

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			int res=0;
			for(int x=0;x<=n;x++){
				for(int y=0;y<=m;y++){
					if(i==x&&j==y) continue;
					int dx=x-i,dy=y-j;
					dy=-dy;
					xx[1]=i+dx+dy;yy[1]=j+dx-dy;
					xx[2]=i+dy,yy[2]=j+dx;
					bool flag=true;
					for(int k=1;k<=2;k++){
						if(xx[k]<0||xx[k]>n||yy[k]<0||yy[k]>m) flag=false;
					}
					if(flag) res+=1;
				}
			}
			// for(int x=-100;x<=100;x++){
			// 	if(j+x>m||j+x<0) break;
			// 	for(int y=-100;y<=100;y++){
			// 		if(i+x+y>n||i+x+y<) break;
			// 		if(x==0&&y==0) continue;
			// 		xx[1]=i+x,yy[1]=j-y;
			// 		xx[2]=i+x+y,yy[2]=j+x-y;
			// 		xx[3]=i+y,yy[3]=j+x;
			// 		bool flag=true;
			// 		for(int j=1;j<=3;j++){
			// 			if(xx[j]<0||xx[j]>n||yy[j]<0||yy[j]>m) flag=false;
			// 		}
			// 		if(flag) res+=1;
			// 	}
			// }
			cout<<res<<" \n"[j==m];
		}
	}
}

int main(){
	// freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
