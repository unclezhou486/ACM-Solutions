#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e5+10;

int n;

struct node{
    int t1,t2;
}a[N];

bool cmp(node a,node b){
    return a.t2<b.t2;
}

priority_queue<int,vector<int>,less<int> > q;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].t1>>a[i].t2;
    }
    sort(a+1,a+1+n,cmp);
    int res=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        res+=a[i].t1;
        q.push(a[i].t1);
        if(res<=a[i].t2){
            ans++;
        }
        else{
            res-=q.top();
            q.pop();
        }
    }
    cout<<ans<<'\n';
}