#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N=4e5+10;

int n,l,r;

int a[N];
vector<int> vec;
map<int,int> ma;
int cnt=1;
int b[N];

int lowbit(int x){
    return x&-x;
}

void add(int k,int x){
    for(k;k<N;k+=lowbit(k)){
        b[k]+=x;
    }
}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)){
        res+=b[x];
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>l>>r;
    vec.push_back(l);
    vec.push_back(r);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vec.push_back(a[i]);
        vec.push_back(r-a[i]);
        vec.push_back(l-a[i]);
    }
    sort(vec.begin(),vec.end());
    ma[vec[0]]=cnt;
    for(int i=1;i<vec.size();i++){
        if(vec[i]!=vec[i-1]) cnt++;
        ma[vec[i]]=cnt;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=query(ma[r-a[i]])-query(ma[l-a[i]]-1);
        add(ma[a[i]],1);
    }
    cout<<ans<<'\n';
}