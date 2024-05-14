#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<pair<int,int> > > ne(n);
    vector<int> d(n),f(n);
    vector<long long> dp(n),dplen(n);
    vector<vector<int> > faa(n,vector<int>(20));
    vector<pair<int,int> > qu(n-1);
    vector<pair<int,int> > edge(n);
    vector<pair<int,int> > son(n);
    vector<long long> ans(q); 
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        ne[u].push_back({v,w});
        ne[v].push_back({u,w});
        edge[i]={u,v};
        qu[i]={0,i};
    }
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        x--;
        qu[x].first=q-i;
    }
    sort(qu.begin(),qu.end());
    for(int i=0;i<n;i++){
        f[i]=i;
        son[i]={i,i};
        dplen[i]=0;
    }

    auto dfs = [&] (auto self,int x,int fa) -> void {
        d[x]=d[fa]+1;
        for(int i=1;i<20;i++){
            faa[x][i]=faa[faa[x][i-1]][i-1];
        }
        for(auto [y,w]:ne[x]){
            if(y==fa) continue;
            faa[y][0]=x;
            dp[y]=dp[x]+w;
            self(self,y,x);
        }
    };

    auto lca = [&] (int x,int y) -> int {
        if(x==y) return x;
        if(d[x]<d[y]) swap(x,y);
        for(int i=19;i>=0;i--){
            if(d[faa[x][i]]>=d[y]) x=faa[x][i];
        }
        if(x==y) return x;
        for(int i=19;i>=0;i--){
            if(faa[x][i]!=faa[y][i]) x=faa[x][i],y=faa[y][i];
        }
        return faa[x][0];
    };

    dfs(dfs,0,0);
    long long len=0;

    auto find = [&] (auto self,int x) -> int {
        return f[x]==x?x:f[x]=self(self,f[x]);
    };

    auto merge = [&] (int x,int y) -> void {
        vector<int> vec;
        int xx=find(find,x);
        int yy=find(find,y);
        vec.push_back(son[xx].first);vec.push_back(son[xx].second);
        vec.push_back(son[yy].first);vec.push_back(son[yy].second);
        f[yy]=xx;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                int u=vec[i],v=vec[j];
                long long res=dp[u]+dp[v]-2*dp[lca(u,v)];
                if(res>dplen[xx]){
                    len=max(res,len);
                    dplen[xx]=res;
                    son[find(find,x)]={u,v};
                }
            }
        }
    };
    
    for(int i=0;i<n-1;i++){
        int val=qu[i].first;
        int idx=qu[i].second;
        if(val){
            ans[q-val]=len;
        }
        auto [u,v]=edge[idx];
        merge(u,v);
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}