#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;

int n,m;

int a[N];

bool d[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    d[1][0]=1;
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            if(d[j][i]){
                int x=j;
                int y=(x+a[i+1])%n;
                if(!y) y=n;
                d[y][i+1]=1;
                y=(((x-a[i+1])%n)+n)%n;
                if(!y) y=n;
                d[y][i+1]=1;
            }
        }
    }
    if(d[1][m]){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}