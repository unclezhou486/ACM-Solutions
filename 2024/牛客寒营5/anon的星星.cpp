#include <bits/stdc++.h>

using namespace std;

int n,x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>x;
    if((x+n)%2) cout<<-1<<'\n';
    else cout<<(x+n)/2<<' '<<n-(x+n)/2<<'\n';
}