#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n;
int a[N],v[N];
int l[N],r[N];
bool vis[N];

struct node{
    int xx,yy;
};

bool operator<(const node& a,const node &b){
        return a.xx*b.yy<a.yy*b.xx;
}
bool operator>(const node& a,const node &b){
    return a.xx*b.yy>a.yy*b.xx;
}

struct seg{
    node abc;
    int ll,rr;
};
bool operator>(const seg& a,const seg& b){
    return a.abc>b.abc;    
}
priority_queue<seg,vector<seg>,greater<seg> >q;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>v[i];
        l[i]=i-1,r[i]=i+1;
    }
    for(int i=1;i<n;i++){
        if(v[i]<=v[i+1]) continue;
        node res={(a[i+1]-a[i]),(v[i]-v[i+1])};
        q.push((seg){res,i,i+1});
    }
    while(q.size()){
        seg pos=q.top();
        q.pop();
        int x=pos.ll,y=pos.rr;
        if(vis[x]||vis[y]) continue;
        vis[x]=vis[y]=1;
        int xl=l[x],yr=r[y];
        r[xl]=yr;
        l[yr]=xl;
        if(xl<1||yr>n) continue;
        if(v[xl]<=v[yr]) continue;
        node res={(a[yr]-a[xl]),(v[xl]-v[yr])};
        q.push((seg){res,xl,yr});
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) cnt++;
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++){
        //cout<<l[i]<<' '<<r[i]<<'\n';
        if(!vis[i]) cout<<i<<' ';
    }
    return 0;
}