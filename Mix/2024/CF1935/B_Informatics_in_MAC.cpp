#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int a[N];
int n;
bool v[N];
bool vis[N];
int b[N];

int lowbit(int x){return x&(-x);}

void add(int k,int x){
    for(k;k<=n;k+=lowbit(k)) b[k]+=x;
}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)){
        res+=b[x];
    }
    return res;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        v[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]]=1;
    }
    int res=n;
    for(int i=0;i<n;i++){
        if(!v[i]) {res=i;break;}
    }
    if(!res){
        cout<<2<<'\n';
        cout<<1<<' '<<1<<'\n'<<2<<' '<<n<<'\n';
    }
    else{
        for(int i=1;i<=n;i++){
            b[i]=0;
            vis[i]=0;
        }
        int ll=1;
        int rr=-1;
        for(int i=1;i<=n;i++){
            if(!vis[a[i]+1])add(a[i]+1,1);
            vis[a[i]+1]=1;
            if(query(res)==res){
                rr=i;
                break;
            }
        }
        if(rr==-1){
            cout<<-1<<'\n';
        }
        else{
            for(int i=1;i<=n;i++) vis[i]=0,b[i]=0;
            for(int i=rr+1;i<=n;i++){
                if(!vis[a[i]+1])add(a[i]+1,1);
                vis[a[i]+1]=1;
            }
            if(query(res)==res){
                cout<<2<<'\n';
                cout<<ll<<' '<<rr<<'\n'<<rr+1<<' '<<n<<'\n';
            }
            else{
                cout<<-1<<'\n';
            }
        }
    }
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