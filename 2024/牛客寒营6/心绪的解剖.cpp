#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int a[N],cnt;

//map<int,int> ma;

struct node{
    int x,y,z;
};

map<int,node> ma;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    a[1]=0,a[2]=1;
    cnt=2;
    while(a[cnt]<1e9){
        int i=cnt;
        a[i+1]=a[i]+a[i-1];
        cnt++;
    }
    cnt--;
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=cnt;j++){
            for(int k=1;k<=cnt;k++){
                int res=a[i]+a[j]+a[k];
                if(res>1e9) break;
                //if(ma.count(res)) continue;
                ma[res]={a[i],a[j],a[k]};
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        if(ma.count(n)){
            node res=ma[n];
            cout<<res.x<<' '<<res.y<<' '<<res.z<<'\n';
        }
        else cout<<-1<<'\n';
    }
}