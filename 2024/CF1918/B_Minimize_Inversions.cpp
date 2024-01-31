#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

struct node{
    int x,id;
};
node a[N];
int b[N];
bool cmp(node a,node b){
    return a.x<b.x;
}

void solve(){
   int n;

   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i].x;
   for(int i=1;i<=n;i++) cin>>b[i],a[i].id=b[i];
   sort(a+1,a+1+n,cmp);
   for(int i=1;i<=n;i++){
    cout<<a[i].x<<' ';
   }
   cout<<'\n';
   for(int i=1;i<=n;i++){
    cout<<a[i].id<<' ';
   }
   cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}