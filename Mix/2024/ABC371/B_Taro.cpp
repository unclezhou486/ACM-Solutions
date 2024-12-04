#include <iostream>
#include <map>

using namespace std;

const int N=110;

int n,m;

void solve(){
    map<int,int> ma;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a;
        char b;
        cin>>a>>b;
        if(b=='F'){
            cout<<"No\n";
        }
        else{
            if(ma.count(a)){
                cout<<"No\n";
            }
            else{
                ma[a]=1;
                cout<<"Yes\n";
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}