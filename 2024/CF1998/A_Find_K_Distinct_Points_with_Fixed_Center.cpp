#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void solve(){
    int xc,yc,k;
    cin>>xc>>yc>>k;
    if(k%2){
        cout<<xc<<' '<<yc<<'\n';
        for(int i=1,j=1;i<=k-1;i+=2,j++){
            cout<<xc-j<<' '<<yc<<'\n';
            cout<<xc+j<<' '<<yc<<'\n';
        }
    }
    else{
        for(int i=1,j=1;i<=k;i+=2,j++){
            cout<<xc-j<<' '<<yc<<'\n';
            cout<<xc+j<<' '<<yc<<'\n';
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