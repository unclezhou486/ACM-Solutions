#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+10;

int n,l;

struct node{
    int a,b;
}c[N];

bool cmp(node aa,node bb){
    return aa.b>bb.b;
}

void solve(){
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>c[i].a>>c[i].b;
    }
    int ans=0;
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<=n;i++){
        priority_queue<int,vector<int>,greater<int> > q2;
        priority_queue<int,vector<int>,less<int> > q1;
        int res=0;
        if(c[i].a<=l) ans=max(ans,1ll);
        for(int j=i+1;j<=n;j++){
            while(res+c[i].a+c[j].a+c[i].b-c[j].b>l&&q1.size()){
                q2.push(q1.top());
                res-=q1.top();
                q1.pop();
            }
            while(q2.size()&&res+c[i].a+c[j].a+c[i].b-c[j].b+q2.top()<=l){
                res+=q2.top();
                q1.push(q2.top());
                q2.pop();
            }
            if(res+c[i].a+c[j].a+c[i].b-c[j].b<=l){
                //cout<<i<<' '<<j<<' '<<q1.size()+2<<' '<<res<<'\n';
                ans=max(ans,(long long)(q1.size()+2));
            }
            res+=c[j].a;
            q1.push(c[j].a);
        }
    }
    cout<<ans<<'\n';
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