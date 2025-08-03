#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<int> resa={a,n-a+1},resb={b,m-b+1};
    int ans=1e9;
    auto check = [&](int h,int w) -> int {
        int res=1;
        while(h!=1){
            res++;
            h=(h+1)/2;
        }
        while(w!=1){
            res++;
            w=(w+1)/2;
        }
        return res;
    };
    for(int i=0;i<2;i++){
        ans=min({ans,check(resa[i],m),check(n,resb[i])});
    }
    cout<<ans<<'\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}