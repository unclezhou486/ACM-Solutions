#include <bits/stdc++.h>

using namespace std;

int n;
char c;

char d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>c;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>d;
        if(d==c){
            ans=ans+min(i,n-i+1);
        }
    }
    cout<<ans<<'\n';
}