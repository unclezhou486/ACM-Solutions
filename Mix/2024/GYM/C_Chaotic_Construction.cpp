#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int a[N],b[N];
int n,q;
int lowbit(int x){return x&-x;}

void add(int k,int x){for(;k<=n;k+=lowbit(k))b[k]+=x;}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)){
        res+=b[x];
    }
    return res;
}

void solve(){
    int cnt=0;
    cin>>n>>q;
    while(q--){
        char op;
        int x,y;
        cin>>op;
        if(op=='-'){
            cin>>x;
            a[x]=1;
            add(x,1);
            cnt++;
        }
        else if(op=='+'){
            cin>>x;
            a[x]=0;
            add(x,-1);
            cnt--;
        }
        else if(op=='?'){
            cin>>x>>y;
            bool fl=1;
            if(x>y) swap(x,y);
            int res=query(y)-query(x-1);
            if(res&&cnt-(query(y-1)-query(x))){
                fl=0;
            }
            if(fl) cout<<"possible\n";
            else cout<<"impossible\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}