#include <bits/stdc++.h>
#define PII pair<int,int> 

using namespace std;

void solve(){
    int n;
    int idx;
    cin>>n;
    vector<int> a(n),ans(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==n){
            idx=i;
        }
    }
    priority_queue<PII,vector<PII >,less<PII> >q1,q2;
    for(int i=0;i<n;i++){
        if(i%2==idx%2) q1.push({a[i],i});
        else q2.push({a[i],i});
    }
    for(int i=1;i<=n/2;i++){
        int id=q2.top().second;
        q2.pop();
        ans[id]=i;
    }
    for(int i=n/2+1;i<=n;i++){
        int id=q1.top().second;
        q1.pop();
        ans[id]=i;
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}