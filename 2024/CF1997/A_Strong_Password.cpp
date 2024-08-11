#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(i+1<s.size()){
            if(s[i]==s[i+1]){
                j=i;
                break;
            }
        }
    }
    for(int i=0;i<=j;i++){
        cout<<s[i];
    }
    char c=s[j];
    c+=1;
    if(c>'z') c='a';
    if(j+1<s.size()&&s[j+1]==c) c+=1;
    if(c>'z') c='a';
    cout<<c;
    for(int i=j+1;i<s.size();i++){
        cout<<s[i];
    }
    cout<<'\n';
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