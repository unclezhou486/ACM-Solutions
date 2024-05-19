#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    auto query = [&] (int l,int x) -> int {
        int res;
        cout<<"? "<<l<<' '<<x<<endl;
        cin>>res;
        return res;
    };
    auto answer = [&] (int x) -> void {
        cout<<"! "<<x<<endl;
        int res;
        cin>>res;
    };
    auto check = [&] (int x) -> bool {
        int id=0;
        for(int i=1;i<=k;i++){
            id+=1;
            if(id>n) break;
            id=query(id,x);
        }
        if(id==n) return 1;
        else return 0;
    };
    int maxn=0;
    for(int i=1;i<=n;i++){
        if(query(1,i*n)==n){
            maxn=i;
        }
    }
    if(!maxn) answer(-1);
    else{
        for(int i=1;i<=n/k;i++){
            if(check(i*maxn)){
                answer(i*maxn);
                return;
            }
        }
        answer(-1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}