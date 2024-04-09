#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int a[N];

int chu(int x){
    int res=x/2;
    if(x%2){
        res++;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    int res0=0,res1=0;
    int ans=-1;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c-'0';
        if(a[i]) res1++;
    }
    if(res1>=chu(n)){
        //cout<<0<<'\n';
        ans=0;
        //return;
    }
    for(int i=1;i<=n;i++){
        if(a[i]) res1--;
        else res0++;
        if(res0>=chu(i)&&res1>=chu(n-i)){
            //cout<<i<<'\n';
            //return;
            if(ans==-1) ans=i;
            else{
                if(abs(n-2*ans)>abs(n-2*i)){
                    ans=i;
                }
            }
        }
    }
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