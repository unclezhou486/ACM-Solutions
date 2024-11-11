#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5+10;

int n,k;
int a[N];

struct node{
    int x,id;
}b[N];

bool cmp(node a,node b){
    return abs(a.x)<abs(b.x);
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>b[i].id;
    for(int i=1;i<=n;i++) cin>>b[i].x;
    sort(b+1,b+1+n,cmp);
    int st=0;
    int res=0;
    bool fl=1;
    for(int i=1;i<=n;i++){
        int x=abs(b[i].x);
        res+=k*(x-st);
        st=x;
        res-=b[i].id;        
        if(res<0){
            fl=0;
            cout<<"NO\n";
            break;
        }
    }
    if(fl) cout<<"YES\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}