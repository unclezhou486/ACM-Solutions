#include <bits/stdc++.h>

using namespace std;

int n;

struct node{
    int x,y,id;
}a[110];

bool cmp(node a,node b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    cout<<n/2<<'\n';
    for(int i=1;i<=n;i+=2){
        if(i+1<=n) cout<<a[i].id<<" "<<a[i+1].id<<'\n'; 
    }
}