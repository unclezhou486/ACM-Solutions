#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    bool fl=0;
    for(auto v:s){
        if(v=='|'){
            if(fl){
                fl=0;
            }
            else fl=1;
            //fl=1;
        }
        else{
            if(!fl)cout<<v;
        } 
    }
}