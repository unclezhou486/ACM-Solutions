#include <bits/stdc++.h>

using namespace std;

struct node{
    long long x,y,id;
};

bool cmp(node a,node b){
    if(a.x==b.x) return a.y<b.y;
    return a.x>b.x;
}

void solve(){
    long long n,m,k;
    cin>>n>>m>>k;
    vector<node> a(k);
    for(int i=0;i<k;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    sort(a.begin(),a.end(),cmp);
    long long resy=m+1;
    long long resx=n+1;
    long long anss=0;
    vector<int> ans(k);
    int i=0;
    if(a[i].x==n){
        resy=a[i].y;resx=a[i].x;
        anss+=resy-1;
        ans[a[i].id]=1;
        i=1;
    }
    for(i;i<k;i++){
        if(a[i].x!=resx){
            anss+=(resx-a[i].x-1)*(resy-1);
            anss+=(min(a[i].y,resy)-1);
            resx=a[i].x;
        }
        if(a[i].y<resy){
            resy=a[i].y;
            ans[a[i].id]=1;
        }
    }
    if(resx!=1){
        anss+=(resx-1)*(resy-1);
    }
    cout<<anss<<'\n';
    for(int i=0;i<k;i++){
        if(ans[i]) cout<<1<<" \n"[i==(k-1)];
        else cout<<0<<" \n"[i==(k-1)];
    }
    return;
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