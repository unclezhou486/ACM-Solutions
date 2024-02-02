#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n,m;
int a[N][N];
bool v[N][N];

int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
int ansb,ansp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='#') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i][j]) continue;
            for(int k=0;k<4;k++){
                bool fl=check(i,j,dx[k],dy[k]);
                if(fl){
                    cover(i,j,dx[k],dy[k]);
                    ansb++;
                    break;
                }
            }
            if(v[i][j]) continue;
            for(int k=0;k<4;k++){
                bool fl=check1(i,j,dx[k],dy[k]);
                if(fl){
                    cover1(i,j,dx[k],dy[k]);
                    ansp++;
                    break;
                }
            }
            if(v[i][j]) continue;
            for(int k=0;k<4;k++){
                bool fl=check2(i,j,dx[k],dy[k]);
                if(fl){
                    cover2(i,j,dx[k],dy[k]);
                    ansp++;
                    break;
                }
            }
        }
    }
}