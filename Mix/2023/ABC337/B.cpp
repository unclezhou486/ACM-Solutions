#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
        bool fl=1;
        for(int i=1;i<s.size();i++){
            if(s[i]<s[i-1]) {fl=0;break;}
        }
        if(fl) cout<<"Yes\n";
        else cout<<"No\n";
    
}