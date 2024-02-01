#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,m,a[N];
pair<int,int> b[N];
int h,t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    h=1,t=0;
    for(int i=1;i<=n;i++){
        while(h<=t&&b[h].first+m-1<i) h++;
        while(h<=t&&b[t].second>a[i]) t--;
        b[++t]={i,a[i]};
        if(i>=m) cout<<b[h].second<<'\n';
    }
    //cout<<q[h]<<'\n';
    //for(int i=m;i<=n;i++){
        //while(h>=t)
    //}
}