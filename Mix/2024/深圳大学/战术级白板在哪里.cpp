#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        int ans=0;
        for(int i=0;i<str.size();i+=2){
            int res=0;
            res=str[i]-'0';
            res*=10;
            res=res+str[i+1]-'0';
            ans=max(ans,res);
        }
        cout<<ans<<'\n';
    }
}