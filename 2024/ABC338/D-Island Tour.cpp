#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m+2);
    queue<pair<int,int> > q;
    //vector<pair<int,int> > b(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q1,q2;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<m;i++){
        if(a[i]>a[i+1])q1.push({a[i+1],a[i]});
        else q1.push({a[i],a[i+1]});
        //if(a[i]>a[i+1])
        ans+=max(a[i+1],a[i])-min(a[i],a[i+1]);
        //ans+=a[i]+(n-a[i+1]);
    }
    //cout<<ans<<'\n';
    long long  anss=ans;
    for(int i=1;i<n;i++){
        //cout<<"pre:"<<ans<<'\n';
        //if(q1.size())cout<<q1.top().first<<'\n';
        while(q1.size()&&q1.top().first==i){
            //cout<<"fu:"<<ans<<'\n';
            int a1=min(q1.top().first,q1.top().second),a2=max(q1.top().first,q1.top().second);
            ans+=(a1+(n-a2));
            ans-=(a2-a1);
            //cout<<"fu1:"<<ans<<'\n';
            q2.push({q1.top().second,q1.top().first});
            q1.pop();
        }
        while(q2.size()&&q2.top().first==i){
            int a1=min(q2.top().first,q2.top().second),a2=max(q2.top().first,q2.top().second);
            ans+=(a2-a1);
            ans-=(a1+(n-a2));
            q2.pop();
        }
        //cout<<"sub:"<<ans<<'\n';
        anss=min(anss,ans);
    }
    cout<<anss<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}