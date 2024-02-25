#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;

char a[N];

int e[N<<1],ne[N<<1],h[N],idx;
bool v[N];
void add(int x,int y){
    e[++idx]=y,ne[idx]=h[x],h[x]=idx;
}

bool dfs(int x,char ch){
    bool fl=1;
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(v[j]) continue;
        v[j]=1;
        if(a[j]=='?'){
            if(ch=='d'){
                fl=dfs(j,'p');
            }
            else{
                fl=dfs(j,'d');
            }
        }
        else{
            if(ch=='d'){
                if(a[j]=='d') return 0;
                else fl=dfs(j,a[j]);
            }
            else{
                if(a[j]=='p') return 0;
                else fl=dfs(j,a[j]);
            }
        }
        if(!fl) return 0;
    }
    return 1;
}

void dfss(int x,int ch){
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(v[j]) continue;
        v[j]=1;
        if(a[j]=='?'){
            if(ch=='d'){
                a[j]='p';
            }
            else{
                a[j]='d';
            }
        }
        dfss(j,a[j]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }
    int x=-1;
    for(int i=1;i<=n;i++){
        if(a[i]=='?'){
            x=i;break;
        }
    }
    v[x]=1;
    if(dfs(x,'d')){
        for(int i=1;i<=n;i++) v[i]=0;
        v[x]=1;
        a[x]='d';
        dfss(x,'d');
        for(int i=1;i<=n;i++){
            cout<<a[i];
        }
        return 0;
    }
    for(int i=1;i<=n;i++) v[i]=0;
    v[x]=1;
    if(dfs(x,'p')){
        for(int i=1;i<=n;i++) v[i]=0;
        v[x]=1;
        a[x]='p';
        dfss(x,'p');
        for(int i=1;i<=n;i++){
            cout<<a[i];
        }
        return 0;
    }
    else{
        cout<<-1<<'\n';
    }
}