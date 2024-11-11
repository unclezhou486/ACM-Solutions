// I copy jiangly's code

#include <bits/stdc++.h>

struct HLD {
    int n;
    std::vector<int> siz,top,dep,parent,in,out,seq;
    std::vector<std::vector<int> >adj;
    int cur;
    HLD() {}
    HLD(int n){
        init(n);
    }
    void init(int n){
        this->n=n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur=0;
        adj.assign(n,{});
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u){
        if(parent[u]!=-1){
            adj[u].erase(std::find(adj[u].begin(),adj[u].end(),parent[u]));
        }
        siz[u]=1;
        for(auto &v:adj[u]){
            parent[v]=u;
            dep[v]=dep[u]+1;
            dfs1(v);
            siz[u]+=siz[v];
            if(siz[v]>siz[adj[u][0]]){
                std::swap(v,adj[u][0]);
            }
        }
    }
    void dfs2(int u){
        in[u] = cur++;
        seq[in[u]] = u;
        for(auto v : adj[u]){
            top[v] = v ==adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u,int v){
        while(top[u] != top[v]){
            if(dep[top[u]] > dep[top[v]]) {
                u=parent[top[u]];
            }
            else{
                v=parent[top[v]];
            }
        }
        return dep[u]<dep[v]?u:v;
    }
    int dist(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
    int jump(int u,int k){
        if(dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;

        while(dep[top[u]] > d) {
            u = parent[top[u]];
        } 
        return seq[in[u] - seq[u] + d];
    }
    bool isAncester(int u,int v){
        return in[u] <=in[v] && in[v] < out[u];
    }
    int rootedParent(int u,int v) {
        std::swap(u,v);
        if(u == v) {
            return u;
        }
        if(!isAncester(u,v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(),adj[u].end(),v,[&](int x,int y) {
            return in[x] < in[y];
        }) -1;
        return *it;
    }
    int rootedSize(int u,int v) {
        if(u==v) {
            return n;
        }
        if(!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a,int b,int c){
        return lca(a, b) ^ lca(b, c) ^ (lca(c, a));
    }
};

struct DSU{
    std::vector<int> f,siz;
    DSU() {}
    DSU(int n){
        init(n);
    }
    void init(int n){
        f.resize(n);
        std::iota(f.begin(),f.end(),0);
        siz.assign(n,1);
    }
    int find(int x){
        while(x!=f[x]){
            x=f[x]=f[f[x]];
        }
        return x;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    bool merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y){
            return false;
        }
        siz[x]+=siz[y];
        f[y]=x;
        return true;
    }
    int size(int x){
        return siz[find(x)];
    }
};

struct Diameter {
    int u;
    int v;
    int d;
};

Diameter merge(const Diameter &d1,const Diameter &d2,HLD &t) {
    Diameter res=d1;
    if( d2.d>res.d){
        res=d2;
    }
    for(auto x : {d1.u,d1.v}){
        for(auto y : {d2.u,d2.v}) {
            int d=t.dist(x,y);
            if(d>res.d) {
                res={x,y,d};
            }
        }
    }
    return res;
}

void solve() {
    int n,q;
    std::cin>>n>>q;
    HLD t(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        t.addEdge(u, v);
    }
    t.work();
    std::vector<int> ans(q);
    DSU dsu(n + 1);

    std::vector<std::vector<int> > vec(q + 1);
    std::vector<int> col(n);
    
    for(int i = 0; i < q; i++) {
        int u,v;
        std::cin>>u>>v;
        u--,v--;
        int l=t.lca(u,v);
        for(auto x : {u, v}) {
            while (true) {
                int y = dsu.find(x);
                if(y == n || t.dep[y] < t.dep[l]) {
                    break;
                }
                col[y] = 1;
                vec[i].push_back(y);
                dsu.merge(y ? t.parent[y] : n, y);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (col[i] == 0) {
            vec[q].push_back(i);
        }
    }
    int res=0;
    std::vector<Diameter> dia(n);
    for (int i = 0; i < n; i++) {
        dia[i] = {i, i, 0};
    }
    col.assign(n, 0);
    dsu.init(n);
    auto chk = [&](int x,int y) {
        if(col[x] != col[y]) {
            return;
        }
        x = dsu.find(x);
        y = dsu.find(y);
        dsu.merge(x, y);
        dia[x] = merge(dia[x], dia[y], t);
        res = std::max(res, dia[x].d);
    };
    auto chg = [&](int x,int c) {
        col[x] = c;
        for (auto y : t.adj[x]) {
            chk(x, y);
        }
        if (x) {
            chk(x, t.parent[x]);
        }
    };
    for (int i = 0; i < q; i++) {
        for (auto x : vec[i]) {
            chg(x, 1);
        }
        ans[i] = res;
    }
    col.assign(n, 1);
    dsu.init(n);
    for (int i = 0;i < n; i++) {
        dia[i]={i,i,0};
    }
    res=0;
    for (int i = q - 1; i >= 0; i--) {
        for (auto x : vec[i + 1]) {
            chg(x, 0);
        }
        ans[i] = std::max(ans[i] , res);
    }
    for (int i=0; i < q; i++) {
        std::cout << ans[i] + 1 << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}