#include <bits/stdc++.h>

using namespace std;

const int N=30;

int t,n,a[N];

void solve(){
    cin>>n;
    bool fl1,fl2;
    fl1=fl2=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]%2) fl1=1;
        else fl2=1;
    }
    bool flag;
    if(fl1&&fl2){
        int res=0;
        for(int i=1;i<=n;i++){
            int j=i+1;
            if(j==n+1) j=1;
            if(!((a[i]+a[j])%2)) res++;
            j=i-1;
            if(j==0) j=n;
            if(!((a[i]+a[j])%2)) res++;
        }
        res/=2;
        if(res%2){
            flag=1;
        }
        else flag=0;
    }
    else{
        if(n%2){
            flag=1;
        }
        else flag=0;
    }
    if(flag) cout<<"qcjj\n";
    else cout<<"zn\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}