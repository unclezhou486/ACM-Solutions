#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> p(n+1),f(n+1);
    vector<int> dep(n+1);
    vector<int> mi(30);
    mi[0]=1;
    //cout<<"CCF";
    //cout<<n<<" "<<q<<'\n';

    for(int i=1;i<n;i++){
        int x;
        cin>>x;
    }
    //return;
    for(int i=n;i>=1;i--){
        dep[i/2]=dep[i]+1;
    }
    for(int i=1;i<=20;i++){
        mi[i]=mi[i-1]*2;
    }
    //cout<<"FUC";
    for(int i=1;i<=n;i++) cin>>p[i];
    bool fl=0;
    set<int> que;
    vector<int> d(n+1);
    d[1]=1;
    for(int i=1;i<=n;i++){
        int x=i+1;
        int xx=i+mi[dep[d[i]]];
        if(!dep[d[i]]) continue;
        d[x]=d[i]*2;
        d[xx]=d[i]*2+1;
        //if(xx>n) continue;
        f[x]=i;
        f[xx]=i;
    }
    //for(int i=1;i<=n;i++){
    //    cout<<f[i]<<' ';
    //}
    //cout<<'\n';
    for(int i=1;i<=n;i++){
        if(dep[p[i]]){
            int x=p[i];
            int y=p[i+1];
            int yy=p[i+mi[dep[x]]];
            if(y>yy) swap(y,yy);
            if(y!=x*2||yy!=x*2+1){
                que.insert(i);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        swap(p[x],p[y]);
        if(x!=1)que.insert(f[x]);
        que.insert(f[y]);
        que.insert(x);
        que.insert(y);
        if(p[1]!=1){
            fl=0;
            cout<<"NO\n";
            continue;
        }
        if(fl==1){
            if(x==y-1&&dep[p[x-1]]==1&&max(p[x],p[x+1])==p[x-1]*2+1&&min(p[x],p[x+1])==p[x-1]*2){
                cout<<"YES\n";
            }
            else{
                fl=0;
                cout<<"NO\n";
            }
            continue;
        }
        bool flag=1;
        vector<int> vec;
        for(auto i:que){
            //cout<<i<<'\n';
            int x=p[i];
            if(!dep[x]){
                vec.push_back(i);
                continue;
            }
            if(i+1>n||i+mi[dep[x]]>n){
                flag=0;
                fl=0;
                cout<<"NO\n";
                break;
            }
            int y=p[i+1];
            int yy=p[i+mi[dep[x]]];
            //cout<<x<<' '<<y<<' '<<yy<<'\n';
            if(y>yy) swap(y,yy);
            if(y!=x*2||yy!=x*2+1){
                flag=0;
                fl=0;
                cout<<"NO\n";
                break;
            }
            else{
                vec.push_back(i);
                continue;
            }
        }
        for(auto i:vec){
            que.erase(i);
        }
        if(flag){
            fl=1;
            cout<<"YES\n";
        }
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
7 4
1 1 2 2 3 3
1 2 3 4 5 6 7
*/