#include <bits/stdc++.h>

#define int long long

using namespace std;
using ll = long long;

constexpr int N=3e5+10;

struct node{
    int u,v;
    long long t,w;
};

struct line{
    long long k,b;
}p[N];

int s[N<<2];
int cnt;

struct que{
    long long x;
    int id;
    bool operator<(const que & a){
        return x<a.x;
    }
};

que qu[N];


long long calc(int id,int d){
    return p[id].b+p[id].k*qu[d].x;
}

void add(long long k,long long b){
    cnt++;
    p[cnt].k=k,p[cnt].b=b;
}

int cmp(long long x,long long y){
    if(x>y) return -1;
    if(y>x) return 1;
    return 0;
}

void upd(int root,int cl ,int cr,int u) {
    int &v = s[root],mid=(cl+cr) >>1;
    int bmid= cmp(calc(u,mid),calc(v,mid));
    if(bmid == 1 || (!bmid &&u<v)) swap(u,v);
    int bl = cmp(calc(u,cl),calc(v,cl)),br= cmp(calc(u,cr),calc(v,cr));
    if(bl==1 || (!bl && u<v)) upd(root<<1,cl,mid,u);
    if(br==1 || (!br && u<v)) upd(root<<1|1,mid+1,cr,u);
}

void update(int root,int cl,int cr,int l,int r,int u) {
    if(l<=cl&&cr<=r) {
        upd(root,cl,cr,u);
        return;
    }
    int mid=(cl+cr)>>1;
    if(l<=mid) update(root<<1,cl,mid,l,r,u);
    if(mid<r) update(root<<1|1,mid+1,cr,l,r,u);
}

pair<long long,int> pmax(pair<long long ,int> x,pair<long long,int> y){
    if(cmp(x.first,y.first)==-1){
        return y;
    }
    else if(cmp(x.first,y.first)==1){
        return x;
    }
    else{
        return x.second<y.second?x:y;
    }
}

pair<long long ,int> query(int root,int l,int r,int d){
    if(r<d|| d<l) return {1e18,0};
    int mid=(l+r)>>1;
    long long res=calc(s[root],d);
    if(l==r) return {res,s[root]};
    return pmax({res,s[root]},pmax(query(root<<1,l,mid,d),query(root<<1|1,mid+1,r,d)));
}

void solve() {
    cnt=0;
    int n,m;
    cin>>n>>m;
    vector<node> a(m+10);
    vector<long long> d1(n+10,1e18);
    vector<long long> d2(n+10,1e18);
    p[0].b=1e18;
    vector<vector<pair<int,long long> > > adj1(n+10),adj2(n+10);
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].t>>a[i].w;
        adj1[a[i].u].push_back({a[i].v,a[i].t});
        adj2[a[i].v].push_back({a[i].u,a[i].t});
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>qu[i].x;
        qu[i].id=i;
    }
    memset(s,0,(q<<2)*sizeof (int));
    sort(qu+1,qu+1+q);
    auto dij = [&](vector<vector<pair<int,long long > > > &adj,vector<long long> &d,int s) -> void{
        priority_queue< pair<long long,int> ,vector<pair<long long,int> > ,greater<> > q;
        vector<int> vis(n+10);
        d[s]=0;
        q.push({d[s],s});
        while(q.size()){
            auto [dis,x]=q.top();
            q.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(auto [y,w]:adj[x]){
                if(d[y]>d[x]+w){
                    d[y]=d[x]+w;
                    q.push({d[y],y});
                }
            }
        }
    };
    dij(adj1,d1,1);
    dij(adj2,d2,n);
    // return;
    for(int i=1;i<=m;i++){
        long long k=-a[i].w,b=d1[a[i].u]+d2[a[i].v]+a[i].t;
        add(k,b);
        update(1,1,q,1,q,cnt);
    }
    // for(int i=1;i<=cnt;i++){
    //     cout<<p[i].k<<' '<<p[i].b<<'\n';
    // }
    vector<int> ans(q+10);
    for(int i=1;i<=q;i++){
        ans[qu[i].id]=query(1,1,q,i).first;
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
