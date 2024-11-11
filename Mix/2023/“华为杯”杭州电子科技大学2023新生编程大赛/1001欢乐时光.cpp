#include <bits/stdc++.h>

using namespace std;

int t,n;

string s;

int main(){
    cin>>t;
    while(t--){
        cin>>n>>s;
        if(n<=5){
            cout<<s<<'\n';
        }
        else cout<<"sleep\n";
    }
}