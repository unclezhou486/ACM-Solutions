#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int M=1e6+10;
int n;
int q;
int a[N];
int b[N],c[N],lb,lc;
int f[M];
int pri[N],cnt;

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

bool is(int x){
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return 0;
    }
    return 1;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<int,int> v;
    for(int i=1;i<=n;i++){
        int x=a[i];
        v[x]=1;
        for(int j=2;j<=x/j;j++){
            if(x%j==0){
                v[j]=1;
                f[find(j)]=find(a[i]);
                while(x%j==0) x/=j;
            }
        }
        if(x>1){
            v[x]=1;
            f[find(x)]=find(a[i]);
        }
    }
    set<int> se;
    for(int i=1;i<=n;i++){
        se.insert(find(a[i]));
    }
    if(se.size()==1&&a[1]==1){
        cout<<1<<' '<<n-1<<'\n';
        cout<<1<<'\n';
        for(int i=1;i<n;i++){
            cout<<1<<' ';
        }
        cout<<'\n';
    }
    else if(se.size()==1){
        cout<<-1<<' '<<-1<<'\n';
    }
    else{
        lb=lc=0;
        for(int i=1;i<=n;i++){
            if(find(a[i])==find(a[1]))b[++lb]=a[i];
            else c[++lc]=a[i];
        }
        cout<<lb<<' '<<lc<<'\n';
        for(int i=1;i<=lb;i++) cout<<b[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=lc;i++) cout<<c[i]<<' ';
        cout<<'\n';
    }
    for(auto [x,y]:v) f[x]=x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //cout<<cnt<<'\n';
    for(int i=1;i<=1000000;i++){
        f[i]=i;
    }
    cin>>q;
    while(q--){
        solve();
    }
}