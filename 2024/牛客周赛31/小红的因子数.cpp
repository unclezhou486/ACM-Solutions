#include <bits/stdc++.h>
#define int long long
using namespace std;

int x;

bool is(int x){
    if(x==1) return 0;
    if(x==2||x==3) return 1;
    for(int i=2;i<=x/i;i++){
        if((x%i)==0) return 0;
    }
    return 1;
}

int ans;
signed main(){
    cin>>x;
    for(int i=1;i<=x/i;i++){
        if(x%i) continue;
        if(i*i!=x){
            if(is(i)) ans++;
            if(is(x/i)) ans++;
        }
        else
        {
            if(is(i)) ans++;
        }
    }
    cout<<ans<<'\n';
}