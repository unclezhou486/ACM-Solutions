#include <bits/stdc++.h>

using namespace std;

string s="46cd3f9hijk1mn0pqr57uvwxy2";
map<char,char>ma;

string str;

int main(){
    for(int i=0;i<26;i++){
        char c=s[i];
        ma[c]=i+97;
    }
    while(cin>>str){
        for(auto v:str){
            if(ma.count(v))cout<<ma[v];
            else cout<<v;
        }
        cout<<' ';
    }
}