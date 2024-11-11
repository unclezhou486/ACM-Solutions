#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int a,b;
    a=b=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='D') {if(a==0) a=1;}
        else if(c=='F') {if(a==1) a=2;}
        else if(c=='S') {if(a==2) a=3;}
        else if(c=='d') {if(b==0) b=1;}
        else if(c=='f') {if(b==1) b=2;}
        else if(c=='s') {if(b==2) b=3;}
    }
    cout<<(a==3)<<' '<<(b==3)<<'\n';
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