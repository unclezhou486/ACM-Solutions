#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int n;

int r[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==-1){
            r[0]=i;
        }
        else r[x]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=r[ans];
        cout<<ans<<' ';
    }

}