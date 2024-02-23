#include <bits/stdc++.h>

using namespace std;

const int N=1e2+10;

int n;

int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int ans=n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==1){
            ans--;
        }
    }
    cout<<ans<<'\n';
}