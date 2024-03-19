#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;

bool check(string& s,int x,int y){
    if(s[x]==s[y]||s[x]=='?'||s[y]=='?') return 1;
    else return 0;
}

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    s='0'+s;
    int ans=0;
    for(int len=1;len<=n/2;len++){
        //if(1+len*2-1>n) break;
        int cnt=0;
        for(int i=1;i<=len;i++){
            if(check(s,i,i+len)) cnt++;
        }
        if(cnt==len) ans=len;
        for(int i=2;i+2*len-1<=n;i++){
            if(check(s,i-1,i+len-1)) cnt--;
            //if(s[i-1]==s[i+len-1]||s[i-1]=='?'|)cnt--;
            //if(s[i+len-1]==s[i+2*len-1]) cnt++;
            if(check(s,i+len-1,i+len*2-1)) cnt++;
            if(cnt==len) ans=len;
        }
    }
    cout<<ans*2<<'\n';
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