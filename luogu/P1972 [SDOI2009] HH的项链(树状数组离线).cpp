#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,q;
int a[N];
int b[N];
int la[N];
int ans[N];
struct node{
    int l,r,id;
}qu[N];

vector<pair<int,int> > vec[N];

bool cmp(node a,node b){
    return a.r<b.r;
}

int lowbit(int x){
    return x&(-x);
}

void add(int k,int x){for(;k<=n;k+=lowbit(k)){b[k]+=x;}}
int query(int k){
    int res=0;
    for(;k;k-=lowbit(k)){res+=b[k];}
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        vec[r].push_back({l,i});
    }
    for(int i=1;i<=n;i++){
        if(la[a[i]]){
            add(la[a[i]],-1);
        }
        la[a[i]]=i;
        add(i,1);
        for(int j=0;j<vec[i].size();j++){
            int l=vec[i][j].first;
            ans[vec[i][j].second]=query(i)-query(l-1);
        }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<'\n';
    }
}