#include <bits/stdc++.h>

using namespace std;

int t,n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t>>n;
    while(t--){
        int res1=0,res2=0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x==1) res1++;
            else res2++;
        }
        cout<<abs(res1-res2)<<'\n';
    }
}