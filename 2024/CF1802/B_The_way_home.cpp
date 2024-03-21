#include <bits/stdc++.h>
#define int long long
#define PII pair<long long ,int>
#define PIII pair<pair<long long,long long > ,int>
using namespace std;

const int N=3010;
const long long INF=1e18;
int n,m;
long long p;
long long w[N];
bool v1[N],v2[N]; // out in 
long long d2[N];// shortest road

pair<long long,long long> dp[810]; // times remain

void solve(){
    cin>>n>>m>>p;
    vector<vector<pair<int,int> > > ne(n+1);// ver value
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        dp[i]={INF,INF};
    }
    dp[1]={0,p};
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        ne[x].push_back({y,v});
    }
    priority_queue<PIII,vector<PIII >,greater<PIII > > q;
    for(int i=1;i<=n;i++) v1[i]=0;
    q.push({dp[1],1ll});
    while(q.size()){ //
        int pos=q.top().second;
        q.pop();
        if(v1[pos]) continue;
        v1[pos]=1;
        for(int i=1;i<=n;i++){
            v2[i]=0;
            d2[i]=INF;
        }
        priority_queue<PII,vector<PII >,greater<PII > > qq;
        qq.push({0ll,pos});
        d2[pos]=0;
        while(qq.size()){
            auto [dis,x]=qq.top();
            qq.pop();
            if(v2[x]) continue;
            v2[x]=1;
            for(auto [y,v]:ne[x]){
                if(v2[y]) continue;
                if(d2[y]>d2[x]+v){
                    d2[y]=d2[x]+v;
                    qq.push({d2[y],y});
                }
            }
        }
        //cout<<pos<<'\n';
        // shortest road 
        auto [cnt,res]=dp[pos];
        for(int i=1;i<=n;i++){
            if(i==pos||d2[i]==INF) continue;
            
            //int count=cnt+(d2[i]-res)
            long long count=max(0ll,(d2[i]-res+w[pos]-1)/w[pos]);
            //cout<<i<<' '<<d2[i]<<' '<<count<<'\n';
            long long ress=res+w[pos]*count-d2[i];
            long long cntt=count+cnt;
            if(dp[i].first>=cntt){
                if(dp[i].first==cntt){
                    if(dp[i].second<ress){
                        dp[i]={cntt,ress};
                    }
                }
                else{
                    dp[i]={cntt,ress};
                }
            }
        }
        for(auto [y,v]:ne[pos]){
            q.push({dp[y],y});
        }
    }
    if(dp[n].first==INF) cout<<-1<<'\n';
    else cout<<dp[n].first<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}