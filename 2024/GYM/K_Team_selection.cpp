#include <bits/stdc++.h>

using namespace std;

const int N=4e6+10;

int n;

int a[N];
int c[N];
int ans[N];

int lowbit(int x){
    return x&(-x);
}

void add(int k,int x){
    for(;k<=n;k+=lowbit(k))c[k]+=x;
}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)){
        res+=c[x];
    }
    return res;
}

bool check(int x,int k){
    if(query(x)>=k){
        return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n/2;i++){
        cin>>a[2*i-1];
        add(2*i-1,1);
    }
    for(int i=1;i<=n/2;i++){
        cin>>a[2*i];
        add(2*i,1);
    }
    for(int i=1;i<=n;i++){
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid,a[i])) r=mid;
            else l=mid+1;
        }
        add(l,-1);
        ans[i]=l;
    }
    for(int i=1;i<=n;i+=2){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    for(int i=2;i<=n;i+=2){
        cout<<ans[i]<<' ';
    }
}