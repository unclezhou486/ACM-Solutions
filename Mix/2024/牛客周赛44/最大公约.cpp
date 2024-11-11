#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int >a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,int> ma;
    int ans=0;
    for(int i=1;i<=n;i++){
        ma[a[i]]++;
        ans=max(ans,ma[a[i]]);
    }
    cout<<ans<<'\n';
}