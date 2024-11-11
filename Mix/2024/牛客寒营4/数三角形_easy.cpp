#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e2+10;

int n,m;
int ans;

char a[N][N];

int b[N][N];

int s1[N*3][N],s2[N*3][N];



bool check(int x,int y){
    if(x<1||x>n||y<1||y>m) return 0;
    else return 1;
}

void find(int x,int y){
    for(int q=1;q<=n;q++){
        bool fl=1;
        if(x+q>n||y+q>m||y-q<1) break;
        int idx1=x+y;
        int idx2=(x-y+max(n,m));
        if(s1[idx1][x+q]-s1[idx1][x]!=q) fl=0;
        if(s2[idx2][x+q]-s2[idx2][x]!=q) fl=0;
        if(b[x+q][y+q]-b[x+q][y-q-1]!=(2*q+1))fl=0;
        if(fl) ans++;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='*') b[i][j]=1;
            b[i][j]+=b[i][j-1];
            int idx1=i+j;
            int idx2=i-j+max(n,m);
            if(a[i][j]=='*') s1[idx1][i]=1;
            s1[idx1][i]+=s1[idx1][i-1];
            if(a[i][j]=='*') s2[idx2][i]=1;
            s2[idx2][i]+=s2[idx2][i-1];
        }
    }
    //cout<<1<<'\n';
    //return 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*')find(i,j);
        }
    }
    cout<<ans<<'\n';
}