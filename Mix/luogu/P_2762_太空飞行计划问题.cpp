#include <bits/stdc++.h>

using namespace std;

const int N=110;

int n,m;

int a[N],b[N];
bool v[N];


vector<int> c[N];

vector<int>val1,val2;
vector<tuple<int,int,int> > edges;

constexpr int inf = 1E9;
template<class T>
struct MaxFlow {
    struct _Edge {
        int to;
        T cap;
        _Edge(int to, T cap) : to(to), cap(cap) {}
    };
    
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    
    MaxFlow() {}
    MaxFlow(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T flow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
    
    std::vector<bool> minCut() {
        std::vector<bool> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    
    struct Edge {
        int from;
        int to;
        T cap;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};


void du(int id){
    char tools[10000];
    memset(tools,0,sizeof tools);
    cin.getline(tools,10000);
    int ulen=0,tool;
    while (sscanf(tools+ulen,"%d",&tool)==1)//之前已经用scanf读完了赞助商同意支付该实验的费用
    {//tool是该实验所需仪器的其中一个      
        c[id].push_back(tool);
        edges.emplace_back(id,m+tool,inf);
        //这一行，你可以将读进来的编号进行储存、处理，如连边。
        if (tool==0) 
            ulen++;
        else {
            while (tool) {
                tool/=10;
                ulen++;
            }
        }
        ulen++;
    }    
}

int main(){
    scanf("%d%d",&m,&n);
    int ans=0;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        ans+=a[i];
        du(i);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        v[i]=1;
        res+=b[i];
    }

    for(int i=1;i<=m;i++){
        edges.emplace_back(n+m+1,i,a[i]);
    }
    for(int i=1;i<=n;i++){
        edges.emplace_back(m+i,n+m+2,b[i]);
    }
    MaxFlow<long long> g(n+m+10);
    for(auto [u,v,w]:edges){
        g.addEdge(u,v,w);
    }
    ans-=g.flow(n+m+1,n+m+2);
    //cout<<g.flow(n+m+1,n+m+2)<<'\n';
    vector<bool> pos=g.minCut();
    for(int i=1;i<=m;i++){
        if(pos[i]) cout<<i<<' ';
    }
    cout<<'\n';
    for(int i=1;i<=n;i++){
        if(pos[m+i]) cout<<i<<' ';
    }
    cout<<'\n';
    cout<<ans<<'\n';
    return 0;
}