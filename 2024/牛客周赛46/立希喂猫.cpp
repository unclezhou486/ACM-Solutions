#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    set<int> se;
    vector<long long> a(n+5),b(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],se.insert(b[i]+1);
    int q;
    cin>>q;
    vector<int> qu(q+5);
    for(int i=1;i<=q;i++){
        cin>>qu[i];
        se.insert(qu[i]);
    }
    map<int,int> ma;
    map<int,long long>re;
    se.insert(1);
    int cnt=0;
    for(auto x:se){
        ma[x]=++cnt;
        re[cnt]=x;
    }
    vector<long long> pre(cnt+5);
    vector<long long> ans(cnt+5);
    for(int i=1;i<=n;i++){
        pre[ma[1]]+=a[i];
        pre[ma[b[i]+1]]-=a[i];
    }
    for(int i=1;i<=cnt;i++){
        pre[i]+=pre[i-1];
    }
    ans[1]=pre[1];
    for(int i=2;i<=cnt;i++){
        ans[i]=ans[i-1]+(re[i]-re[i-1]-1)*pre[i-1]+pre[i];
    }
    for(int i=1;i<=q;i++){
        cout<<ans[ma[qu[i]]]<<'\n';
    }
}