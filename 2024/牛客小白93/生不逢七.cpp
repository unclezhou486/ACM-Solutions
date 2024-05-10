#include <bits/stdc++.h>

bool check(int x){
    if(x%7==0) return 1;
    else{
        while(x){
            int y=x%10;
            if(y==7) return 1;
            x/=10;
        }
        return 0;
    }
}

void solve(){
    int n,a,k;
    std::cin>>n>>a>>k;
    a++;
    int cnt=0;
    while(cnt<k){
        if(check(a)){
            std::cout<<'p'<<' ';
        }
        else{
            std::cout<<a<<' ';
        }
        for(int i=1;i<=n;i++){
            a++;
        }
        cnt++;
    }
    std::cout<<'\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}