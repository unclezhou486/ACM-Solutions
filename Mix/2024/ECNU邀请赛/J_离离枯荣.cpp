#include <bits/stdc++.h>

using namespace std;

const int N=2000;

int n;

char a[N][N];

void solve(int x,int y,int xx,int yy){
    if(x==xx&&y==yy){
        cout<<a[x][y];
        return ;
    }
    solve(x,y,x+(xx-x+1)/2-1,y+(yy-y+1)/2-1);
    solve(x,y+(yy-y+1)/2,x+(xx-x+1)/2-1,yy);
    solve(x+(xx-x+1)/2,y,xx,y+(yy-y+1)/2-1);
    solve(x+(xx-x+1)/2,y+(yy-y+1)/2,xx,yy);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    solve(1,1,n,n);
}