#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int a[N];
int b[N];
int n,x;
void check(){
    int l=1,r=n+1;
    while(r-l!=1){
        int mid=(l+r)>>1;
        if(a[mid]<=x) l=mid;
        else r=mid;
    }
    if(a[l]==x) cout<<"Yes\n";
    else cout<<"CCF\n";
}

void solve(){
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i],b[a[i]]=i;
    set<int> se;
    int l=1,r=n+1;
    while(r-l!=1){
        int mid=(l+r)>>1;
        se.insert(mid);
        if(a[mid]<=x) l=mid;
        else r=mid;
    }
    //for(auto xx:se) cout<<xx<<' ';
    //cout<<'\n';
    if(a[l]==x){
        cout<<0<<'\n';
        return;
    }
    if(se.find(b[x])==se.end()){
        cout<<1<<'\n';
        cout<<l<<' '<<b[x]<<'\n';
        swap(a[l],a[b[x]]);
        //if(check()) cout<<"Yes\n"
        //swap()
        return;
    }
    if(a[l]<=x){
        cout<<1<<'\n';
        cout<<l<<' '<<b[x]<<'\n';
        swap(a[l],a[b[x]]);
        //check();
        return;
    }
    cout<<2<<'\n';
    int y=-1;
    for(int i=1;i<=n;i++){
        if(se.find(i)==se.end()&&a[i]<x){
            y=i;
            break;
        }
    }
    if(y!=-1){
        cout<<b[x]<<' '<<y<<'\n';
        cout<<y<<' '<<l<<'\n';
        swap(a[b[x]],a[y]);
        swap(a[y],a[l]);
        
        //check();
        return;
    }
    se.clear();
    l=1,r=n+1;
    while(r-l!=1){
        int mid=(l+r)>>1;
        se.insert(mid);
        if(a[mid]<x) l=mid;
        else r=mid;
    }
    //y=-1;
    for(int i=1;i<=n;i++){
        if(se.find(b[x])==se.end()&&a[i]>x){
            y=i;
            break;
        }
    }
    cout<<b[x]<<' '<<y<<'\n';
    cout<<y<<' '<<l<<'\n';
    swap(a[b[x]],a[y]);
    swap(a[y],a[l]);
    //check();

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}