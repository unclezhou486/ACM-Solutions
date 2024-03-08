#include <bits/stdc++.h>

using namespace std;

int a,b;

string s;

int main(){
    cin>>s;
    cin>>s;
    if(s[0]=='0'||s[0]=='1'){
        a=s[0]-'0';
        cin>>s;
        cin>>s;
        if(s.size()>2){
            cin>>s;
            b=s[0]-'0';
            cout<<(a|b)<<'\n';
        }
        else{
            cin>>s;
            cin>>s;
            cin>>s;
            b=s[0]-'0';
            cout<<(a&b)<<'\n';
        }
    }
    else{
        cin>>s;
        cin>>s;
        int a=s[0]-'0';
        if(a==0) a=1;
        else a=0;
        cout<<a<<'\n';
    }
}