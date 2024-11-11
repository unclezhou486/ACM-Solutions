#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n;
int a[N];
void solve(){
    cin>>n;
    int cnt=0;
    int minn=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<minn){
            minn=a[i];cnt=1;
        }
        else if(a[i]==minn){
            cnt++;
        }
    }
    if(cnt>1){
        bool fl=0;
        for(int i=1;i<=n;i++){
            if(a[i]%minn!=0){
                fl=1;
            }
        }
        if(fl){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
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