#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    map<int,int> ma;
    ma[a]++,ma[b]++,ma[c]++;
    if(ma[k]){
        cout<<0<<'\n';
    }
    else{
        if(k>2){
            cout<<-1<<'\n';
        }
        else if(k==0){
            cout<<1<<'\n';
        }
        else if(k==1){
            if(ma[0]==0) cout<<2<<'\n';
            else cout<<1<<'\n';
        }
        else{
            if(ma[0]&&ma[1]){
                cout<<1<<'\n';
            }
            else if(ma[0]||ma[1]){
                cout<<2<<'\n';
            }
            else{
                cout<<3<<'\n';
            }
        }
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