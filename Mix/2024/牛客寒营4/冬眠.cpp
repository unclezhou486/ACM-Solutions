#include <bits/stdc++.h>

using namespace std;

const int N=110;

int n,m,x,y;
char a[N][N];
int op[N],b[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int p,q;
    cin>>p>>q;
    for(int i=1;i<=q;i++){
        cin>>op[i]>>b[i];
    }
    while(p--){
        for(int i=q;i>=1;i--){
            if(op[i]==1){
                if(b[i]==x){
                    if(y==1) y=m;
                    else y-=1;
                }
            }
            else{
                if(b[i]==y){
                    if(x==1) x=n;
                    else x-=1;
                }
            }
        }
    }
    cout<<a[x][y]<<'\n';
}