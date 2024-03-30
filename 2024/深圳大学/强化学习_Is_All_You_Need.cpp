#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e3+10;

int n,m;

int a[N][N];
int s[N][N];
int ru[N];
int d[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
            ru[s[i][j]]++;
        }
    }
    for(int i=1;i<=n+1;i++){
        d[i]=-1e18;
    }
    ru[1]=0;
    queue<int> qu;
    for(int i=2;i<=n;i++){
        if(!ru[i]){
            qu.push(i);
        }
    }
    while(qu.size()){
        int x=qu.front();
        qu.pop();
        for(int i=1;i<=m;i++){
            int y=s[x][i];
            ru[y]--;
            if(!ru[y]) qu.push(y);
        }
    }
    queue<int>q;
    q.push(1);
    d[1]=0;
    while(q.size()){
        int x=q.front();
        //cout<<x<<' '<<d[x]<<'\n';
        q.pop();
        if(x==n+1) continue;
        for(int i=1;i<=m;i++){
            int y=s[x][i];
            int w=a[x][i];
            ru[y]--;
            d[y]=max(d[y],d[x]+w);
            if(!ru[y]){
                q.push(y);
            }
        }
    }
    //for(int i=1;i<=n+1;i++){
    //    cout<<d[i]<<' ';
    //}
    //cout<<'\n';
    cout<<d[n+1]<<'\n';   
}