#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n,m;
char a[N][N];
char ans[N][N];

int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};

bool check(int x,int y){
    for(int i=0;i<8;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(a[xx][yy]=='H') return 1;
    }
    return 0;
}

bool check1(int x,int y){
    for(int i=0;i<8;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(a[xx][yy]!='L') return 0;
    }
    return 1;
}

bool check2(int x,int y){
    for(int i=0;i<8;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(a[xx][yy]=='L') return 1;
    }
    return 0;    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
        a[0][i]='M';
        a[n+1][i]='M';
        a[i][0]='M';
        a[i][n+1]='M';
    }
    a[0][0]='M';
    a[0][n+1]='M';
    a[n+1][0]='M';
    a[n+1][n+1]='M';
    //for(int i=0;i<=n+1;i++){
    //    for(int j=0;j<=m+1;j++){
    //        cout<<a[i][j];
    //    }
    //    cout<<'\n';
    //}
    //return 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='M'){
                ans[i][j]='M';
            }           
            else if(a[i][j]=='H'||check(i,j)){
                ans[i][j]=a[i][j];
            }
            else if(a[i][j]=='L'){
                if(check1(i,j))ans[i][j]='S';
                else ans[i][j]='L';
            }
            else{
                if(check2(i,j)&&!check(i,j)) ans[i][j]='N';
                else ans[i][j]='B';
            }
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}