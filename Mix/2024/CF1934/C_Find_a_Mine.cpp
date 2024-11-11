#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    auto query =[&](int x,int y){
        if(x<1||x>n||y<1||y>m) return -1;
        cout<<"? "<<x<<' '<<y<<endl;
        int z;
        cin>>z;
        return z;
    };
    int d=query(1,1);
    int lx=max(1,2+d-m);
    int p=query(lx,2+d-lx);
    int rx=max(1,2+d-n);
    int q=query(2+d-rx,rx);
    if(query(lx+p/2,2+d-lx-p/2)==0){
        cout<<"! "<<lx+p/2<<" "<<2+d-lx-p/2<<endl;
    }
    else{
        cout<<"! "<<2+d-rx-q/2<<' '<<rx+q/2<<endl;
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