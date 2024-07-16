#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100000],ans;
int n,m,p;
int mod;
int zuhe[5100][5100];

bool dfss(int id,int res){
    if(id==n){
        if(res==1) return 1;
        else return 0;
    }
    if(dfss(id+1,res&a[id])) return 1;
    else return dfss(id+1,res);
}

void dfs(int id,int x){
    a[id]=x;
    if(id==n){
        for(int i=1;i<=n;i++) cout<<a[i]<<" \n";
        if(dfss(0,(1<<m)-1))ans++;
        return;
    }
    for(int i=x;i<(1<<m);i++){
        dfs(id+1,i);
    }
}

void solvee(){
    dfs(0,0);
    cout<<ans<<'\n';
}

long long qmi(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}

long long inv(long long x){
    return qmi(x,mod-2);
}


void solve(){
    cin>>n>>m>>p;
    mod=p;
    zuhe[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            zuhe[i][j]=zuhe[i-1][j];
            if(j-1>=0)zuhe[i][j]+=zuhe[i-1][j-1];
            zuhe[i][j]%=mod;
        }
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=0;j<=m;j++){
    //        cout<<zuhe[i][j]<<' ';
    //    }
    //    cout<<'\n';
    //}
    
    long long ans=0;
    long long c=1;
    for(int i=1;i<=n;i++){
        long long res=0;
        c=zuhe[n][i];
        res=qmi(2,i)-1;res%=mod;res+=mod;res%=mod;
        res=qmi(res,m-1);
        long long res1=qmi(2,(m-1)*(n-i));
        res=c*res;res%=mod;
        res=res*res1;res%=mod;
        ans+=res;
        ans%=mod;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //solvee();
    solve();
    return 0;
}