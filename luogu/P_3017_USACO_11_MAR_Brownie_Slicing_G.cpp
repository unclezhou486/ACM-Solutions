#include <bits/stdc++.h>

using namespace std;

const int N=5e2+10;

int n,m,a,b;
int aa[N][N],s[N][N];

bool check(int x){
    int pre=0;
    int dis=0;
    int ress=0;
    for(int i=1;i<=n;i++){
        int res=0;
        dis=0;
        for(int j=1;j<=m;j++){
            if(dis+(s[i][j]-s[i][j-1])-(s[pre][j]-s[pre][j-1])<x){
                dis+=(s[i][j]-s[i][j-1])-(s[pre][j]-s[pre][j-1]);
            }
            else{
                res++;
                dis=0;
            }
        }
        if(res>=b){
            ress++;
            pre=i;
        }
    }
    if(ress>=a) return 1;
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>aa[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+aa[i][j];
        }
    }
    int l=0,r=s[n][m];
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
}