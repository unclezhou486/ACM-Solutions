#include <bits/stdc++.h>

using namespace std;

const int N=4e5+10;

int tr[N*32][2],id[N*32],tot,root;

int ans[40],bit[40],res;

int n,m;

int newnode(){
    return tot++;
}

void init(){
    memset(tr,0,sizeof tr);
    tot=1;
    root=newnode();
}



void insert(int x,int idx){
    int p=root;
    for(int i=31;i>=0;i--){
        int t=(x>>i)&1;
        if(!tr[p][t]) tr[p][t]=newnode();
        if(tr[p][1]&&tr[p][0]) bit[i]=p;
        p=tr[p][t];
    }
    id[p]=idx;
}

int getmin(int p,int k){
    for(int i=k-1;i>0;i--){
        int t=ans[i];
        if(tr[p][t]) p=tr[p][t];
        else p=tr[p][t^1];
    }
    return id[p];
}

int getmax(int p,int k){
    for(int i=k-1;i>0;i--){
        int t=ans[i]^1;
        if(tr[p][t]) p=tr[p][t];
        else p=tr[p][t^1];
    }
    return id[p];
}

int query(int x){
    cout<<"? "<<x<<endl;
    int res;
    cin>>res;
    return res;
}

void answer(int x){
    cout<<"! "<<x<<endl;
}

void solve(){
    cin>>n>>m;
    vector<int> a(n+1);
    init();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        insert(a[i],i);
    }
    while(m--){
        int res=0;
        for(int i=1;i<=30;i++) ans[i]=0;
        for(int i=1;i<=30;i++){
            if(!bit[i-1]) continue;
            int id1=getmax(tr[bit[i-1]][0],i),id2=getmin(tr[bit[i-1]][1],i);
            if(query(id1)!=id2) ans[i]=1,res+=(1<<(i-1));
        }
        answer(res);
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
/*
5 1
1 2 3 4 5
*/