#include <bits/stdc++.h>

using namespace std;

int a[20],b[20];
int n,x;
bool flag=0;

void dfs(int pos,int y){
    if(flag) return;
    a[pos]=y;
    if(pos==n){
        int res=0;
        bool fl=1;
        for(int i=1;i<=n;i++){
            res*=10;
            res+=a[i];
            if(a[i]==b[i]) fl=0;
        }
        if(res&&fl){
            cout<<res<<'\n';
            flag=1;
        }
        return;
    }
    for(int i=0;i<3;i++){
        dfs(pos+1,i);
    }
}

void solve(){
    flag=0;
    cin>>x;
    int xx=x;
    n=0;
    while(xx){
        n++;
        xx/=10;
    }
    xx=x;
    for(int i=n;i>=1;i--){
        b[i]=xx%10;
        xx/=10;
    }
    dfs(0,0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}