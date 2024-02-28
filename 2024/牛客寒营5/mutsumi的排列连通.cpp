#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;
int a[N],b[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    if(n==1||(n==2&&a[1]==b[1])){
        cout<<-1<<'\n';
    }
    else{
        int ans=2;
        for(int i=1;i<=n;i++){
            if(i!=1&&i!=n){
                if(a[i]==b[i]) ans=1;
            }
            if(i>1) if(a[i]==b[i-1]) ans=1;
            if(i<n) if(a[i]==b[i+1]) ans=1;
        }
        cout<<ans<<'\n';
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