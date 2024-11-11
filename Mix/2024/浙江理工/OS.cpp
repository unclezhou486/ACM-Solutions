#include <bits/stdc++.h>
#define int __int128

using namespace std;

const int N=1e4+10;

//int t1[N],t2[N];

struct node{
    int t1,t2,id;
}a[N];

bool cmp(node a,node b){
    if(a.t1==b.t1) return a.id<b.id;
    return a.t1<b.t1;
}

bool v[N];

long long ans[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    signed n;
    cin>>n;
    for(int i=1;i<=n;i++){
        signed x,y;
        cin>>x>>y;
        a[i].t1=x,a[i].t2=y;
        //cin>>a[i].t1>>a[i].t2;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    int res=0;
    //cout<<res<<'\n';
    //res=0;
    for(int i=1;i<=n;i++){
        node ress;
        ress.t1=-1;
        for(int j=1;j<=n;j++){
            if(v[a[j].id]) continue;
            //fl=1;
            if(ress.t1==-1){
                ress=a[j];
            }
            else{
                if(a[j].t1>res) break;
                if((res-ress.t1)*a[j].t2<=(res-a[j].t1)*ress.t2){
                    if((res-ress.t1)*a[j].t2==(res-a[j].t1)*ress.t2){
                        if(ress.t1>a[j].t1) ress=a[j];
                        else if(ress.t1==a[j].t1&&ress.id>a[j].id) ress=a[j];
                    }
                    else ress=a[j];
                } 
            }
        }
        res=max(res,ress.t1);
        ans[ress.id]=res;
        res+=ress.t2;
        v[ress.id]=1;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<'\n';
    }
}