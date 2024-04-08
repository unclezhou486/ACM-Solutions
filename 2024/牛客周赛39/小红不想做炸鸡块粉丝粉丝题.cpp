#include <bits/stdc++.h>

using namespace std;



int main(){
    int x;
    int res=0;
    cin>>x;
    //int res=;
    for(int i=1;i<=5;i++){
        int y;
        cin>>y;
        res+=y;
    }
    if(x*30>=res){
        cout<<"No\n";
    }
    else cout<<"Yes\n";
}