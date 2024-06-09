#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,x;
    cin>>n>>x;
    int ans=0;
    for(long long i=1;i<=x/i;i++){
        if((x%i)==0){
            long long res=x/i;
            ans^=1;
            if(res<=n&&res!=i) ans^=1;
        }
    }
    if(ans) cout<<"ON\n";
    else cout<<"OFF\n";
}