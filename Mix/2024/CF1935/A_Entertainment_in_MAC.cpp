#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    string s1,s2,s3,s4;
    string ss;
    ss=s;
    s1=s;
    reverse(s.begin(),s.end());
    s4=ss+s;
    s2=s;
    s3=s+ss;
    if(n%2){
        cout<<min(s2,s4)<<'\n';
    }
    else{
        cout<<min(s1,s3)<<'\n';
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