#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    if(a!=b){
        cout<<4<<'\n';
        cout<<a<<'\n'<<b<<'\n'<<a+b<<'\n'<<b+a<<'\n';
    }
    else{
        cout<<2<<'\n';
    cout<<a<<'\n'<<a+a<<'\n';
    } 
}