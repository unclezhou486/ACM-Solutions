#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int a[N];
int n,q;
int b[520][N];

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[0][i]=a[i];
    }
    for(int i=1;i<512;i++){
        for(int j=0;i+j<n;j++){
            b[i][j]=b[i-1][j]^b[i-1][j+1];
        }
    }
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x<512){
            cout<<b[x][y]<<'\n';
        }
        else{
            int xx=x%512;
            int ans=b[xx][y];
            int xxx=x-xx;
            for(int yy=xxx;yy;yy=(yy-1)&xxx){
                if(xx+y+yy<n) ans^=b[xx][y+yy];
            }
            cout<<ans<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}