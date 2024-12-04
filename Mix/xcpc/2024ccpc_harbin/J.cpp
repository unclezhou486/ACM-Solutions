#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>

using namespace std;

const int N=1e5+10;

queue<int> qu[N];

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+10),x(m+10),t(m+10),cap(n+10);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cap[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>x[i]>>t[i];
        qu[t[i]].push(i);
    }
    for(int i=1;i<=n;i++){
        qu[i].push(m+1);
    }
    priority_queue<PII,vector<PII>,greater<PII> > q;
    for(int i=1;i<=n;i++){
        q.push({qu[i].front(),i});
        qu[i].pop();
    }
    for(int i=1;i<=m;i++){
        int res=x[i]-x[i-1];
        while(q.size()&&res){
            auto [tid,aid]=q.top();
            if(res>=a[aid]){
                res-=a[aid];
                a[aid]=0;
                q.pop();
            }
            else{
                a[aid]=a[aid]-res;
                res=0;
            }
        }
        if(res){
            cout<<x[i]-res<<"\n";
            for(int i=1;i<=n;i++){
                while(qu[i].size()) qu[i].pop();
            }
            return;
        }
        if(q.size()&&q.top().second==t[i]) q.pop();
        q.push({qu[t[i]].front(),t[i]});
        a[t[i]]=cap[t[i]];
        qu[t[i]].pop();
    }
    long long ans=x[m];
    for(int i=1;i<=n;i++){
        ans+=a[i];
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        while(qu[i].size()) qu[i].pop();
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}