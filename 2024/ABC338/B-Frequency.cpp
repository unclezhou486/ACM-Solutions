#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    map<char,int>m;
    int maxn=0;
    char ans;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    for(char i='a';i<='z';i++){
        if(m[i]>maxn){
            maxn=m[i];
            ans=i;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}