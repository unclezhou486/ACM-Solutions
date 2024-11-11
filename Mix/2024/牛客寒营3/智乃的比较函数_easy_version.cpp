#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n==1){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==y){
            if(z==1) cout<<"No\n";
            else cout<<"Yes\n";
        }
        else cout<<"Yes\n";
    }
    else{
        int x,y,z;
        cin>>x>>y>>z;
        if(x==y){
            if(z==1) {cin>>x>>y>>z;cout<<"No\n";return;}
        }
        //pair<int,int> pos={x,y};
        //auto pos={x,y,z};
        pair<pair<int,int>,int> pos={{x,y},z};
        cin>>x>>y>>z;
        if(x==y){
            if(z) {cout<<"No\n";return;}
            else{
                cout<<"Yes\n";
                return;
            }
        }
        if(x==pos.first.second&&y==pos.first.first){
            if(pos.second==1){
                if(z==1){
                    cout<<"No\n";
                    return;
                }
                else{
                    cout<<"Yes\n";
                    return;
                }
            }
            if(pos.second==0){
                cout<<"Yes\n";
                return;
            }
        }
        if(x==pos.first.second) swap(x,y),z^=1;
        if(x==pos.first.first&&y==pos.first.second){
            if(z==pos.second){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
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