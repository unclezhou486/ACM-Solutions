#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int n;

int e[N],ne[N],h[N],idx;
int ru[N];
int ruu[N];
int f[N][30],dep[N];

void add(int x,int y){
    e[++idx]=y,ne[idx]=h[x],h[x]=idx;
}



void dfs(int x,int fa){
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=1;i<30;i++){
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=29;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if(x==y) return x;
    for(int i=29;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i],y=f[y][i];
        }
    }
    return f[x][0];
}

int top(int x,int lc){
    for(int i=29;i>=0;i--){
        while(dep[f[x][i]]>=dep[lc]+1)x=f[x][i];
    }
    return x;
}

bool topu(vector<vector<int> > &vec1){
    int cnt=0;
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(!ruu[i]) que.push(i),cnt++;
    }
    while(que.size()){
        int x=que.front();
        //cout<<x<<' ';
        que.pop();
        for(int i=h[x];i;i=ne[i]){
            int j=e[i];
            ruu[j]--;
            if(!ruu[j]) que.push(j),cnt++;
        }
        for(auto y:vec1[x]){
            ruu[y]--;
            if(!ruu[y]) que.push(y),cnt++;
        }
    }
    if(cnt==n) return 1;
    else return 0;
}

void solve(){
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        ru[i]++;
        add(x,i);
    }
    dfs(1,1);
    //return;
    int q;
    cin>>q;
    while(q--){
        vector<vector<int> > adj(n+5);
        for(int i=1;i<=n;i++){
            ruu[i]=ru[i];
        }
        int m;
        cin>>m;
        vector<int> qu(m+5);
        for(int i=1;i<=m;i++){
            cin>>qu[i];
        }
        bool flag=true;
        for(int i=2;i<=m;i++){
            if(dep[qu[i]]<dep[qu[i-1]]) flag=false;
        }
        if(!flag){
            cout<<"No\n";
        }
        else{
            for(int i=1;i<m;i++){
                if(dep[qu[i]]==dep[qu[i+1]]){
                    int lc=lca(qu[i],qu[i+1]);
                    int a=top(qu[i],lc);
                    int b=top(qu[i+1],lc);
                    adj[a].push_back(b);
                    ruu[b]++;
                }
            }
            if(topu(adj)){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}