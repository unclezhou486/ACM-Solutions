#include <bits/stdc++.h>

using namespace std;

int print(int x){
    string str="";
    int res=0;
    while(x){
        char ch=(x%2)+'0';
        (x%2);
        x/=2;
        str=ch+str;
        if(ch=='0') res++;
        else break;
    }
    return res;
    //cout<<str<<'\n';
}

void solve(){
    int x,y;
    cin>>x>>y;
    cout<<(int)pow(2,print(x^y))<<'\n';
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