#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;

int a[N];

int e[N],ne[N],h[N],idx;
int dfn[N],cnt,siz[N];
int rnk[N];
bool fl=1;
int ans[N];

int d[N];

int lowbit(int x){
    return x&(-x);
}

void ad(int k,int x){for(;k<=n;k+=lowbit(k))d[k]+=x;}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)){
        res+=d[x];
    }
    return res;
}

void add(int x,int y){
    e[++idx]=y,ne[idx]=h[x],h[x]=idx;
}

int dfs(int x,int fa){
    siz[x]=1;
    dfn[x]=++cnt;
    rnk[cnt]=x;
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        siz[x]+=dfs(j,x);
    }
    return siz[x];

}

void dfss(int x,int fa){
    if(!fl) return;
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfss(j,x);
        if(!fl) return;
    }
    if(a[x]==1){
        int res=siz[x]-query(dfn[x]+siz[x]-1)-query(dfn[x]-1);
        if(res==1){
            fl=0;
            return;
        }
        else{
            if(res%2){
                int id=0;
                for(int i=dfn[x];i<=dfn[x]+siz[x]-1;i++){
                    int j=rnk[i];
                    if(ans[j]) {i+=(siz[j]-1);continue;}
                    if(id<3){
                        ans[j]=1;
                        ad(i,1);
                        id++;
                        res--;
                    }
                    else{
                        if(res%2){
                            ans[j]=1;
                            ad(i,1);
                        }
                        else{
                            ans[j]=2;
                            ad(i,1);
                        }
                        res--;
                    }
                }
            }
            else{
                for(int i=dfn[x];i<=dfn[x]+siz[x]-1;i++){
                    int j=rnk[i];
                    if(ans[j]) {i+=(siz[j]-1);continue;}
                        if(res%2){
                            ans[j]=1;
                            ad(dfn[j],1);
                        }
                        else{
                            ans[j]=2;
                            ad(dfn[j],1);
                        }
                        res--;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='R') a[i]=1;
        else a[i]=0;
    }
    for(int i=1;i<n;i++){
        int u;
        cin>>u;
        add(u,i+1);
    }
    dfs(1,1);
    dfss(1,1);
    if(!fl){
        cout<<-1<<'\n';
    }
    else{
        for(int i=1;i<=n;i++){
            if(ans[i])cout<<ans[i];
            else cout<<1;
        }
    }
}