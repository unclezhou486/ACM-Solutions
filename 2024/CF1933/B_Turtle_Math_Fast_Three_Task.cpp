#include <bits/stdc++.h>

using namespace std;

int n;

void solve(){
    cin>>n;
    int sum=0;
    bool f1=0,f2=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum+=x;
        if(x%3==1){
            f1=1;
        }
        else if(x%3==2){
            f2=1;
        }
    }
    int ans=0;
    if(sum%3==1){
        if(f1){
            ans=1;
        }
        else{
            ans=2;
        }        
    }
    else if(sum%3==2){
        ans=1;
    }
    else{
        ans=0;
    }
    //cout<<sum<<' '<<f1<<' '<<f2<<' ';
    cout<<ans<<'\n';
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