#include <bits/stdc++.h>

using namespace std;

int x,n;

int main(){
    cin>>x;
    cin>>n;
    char cmax;
    char c;
    int maxn=0;
    while(n--){
        int xx;
        cin>>c>>xx;
        if(xx>maxn){
            maxn=xx;
            cmax=c;
        }
    }
    if(maxn*1000<x){
        cout<<-1<<'\n';
    }
    else{
        for(int i=1;i<=1000;i++){
            cout<<cmax;
        }
    }
}