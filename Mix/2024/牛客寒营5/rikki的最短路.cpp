#include <bits/stdc++.h>
#define int long long
using namespace std;

int t,a,k;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t>>a>>k;
    if(abs(a)<k){
        cout<<(abs(a))+abs(max(t,a)-min(t,a))<<'\n';
    }
    else{
        if(a<0&&t<0){
            if(a>t){
                cout<<abs(t)<<'\n';
            }
            else{
                cout<<abs(a)+abs(t-a)<<'\n';
            }
        }
        else if(a>0&&t>0){
            if(a<t){
                cout<<t<<'\n';
            }
            else{
                cout<<a+a-t<<'\n';
            }
        }
        else{
            cout<<(3*abs(t)+2*abs(a))<<'\n';
        }
    }
}