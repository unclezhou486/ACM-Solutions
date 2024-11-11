#include <bits/stdc++.h>
#define int long long

using namespace std;

int ans,x,dig0;

int dig(int x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}

int query(int x){
    int res;
    cout<<"query "<<x<<endl;
    cin>>res;
    return res;
}

void answer(int x){
    cout<<"answer "<<x<<endl;
}

bool check(int x,int y){
    if(query(x*y)==dig0+x) return 1;
    else return 0;
}


signed main(){
    ans=0;
    x=1;
    dig0=query(0);
    for(int i=1;i<=17;i++){
        x*=10;
    }
    for(int i=17;~i;i--){
        int l=0,r=9;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid,x)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        ans+=x*(9-l);
        x/=10;
    }
    answer(ans);
}