#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

struct point{
    int x,y;
}s,t;

const point operator - (point& a,point& b){return (point){a.x-b.x,a.y-b.y};}
long long dot(point a,point b){return a.x*b.x+a.y*b.y;}
long long det(point a,point b){return a.x*b.y-a.y*b.x;}

struct bit{
    array<int,N>a={};
    int lowbit(int x){return x&(-x);}
    void add(int k,int x){for(k;k<N;k+=lowbit(k)) a[k]+=x;}
    int query(int x){
        int res=0;
        for(;x;x-=lowbit(x)) res+=a[x];
        return res;
    }
};

long long count_nixu(vector<int> p,vector<int> q){
    long long cnt=0,res=0;
    array<int,N> pos={};
    for(auto x:p) pos[x]=++cnt;
    bit B;
    for(auto x:q){
        res+=B.query(N-1)-B.query(pos[x]);
        B.add(pos[x],1);
    }
    return res;
}

void solve(){
    int xs,ys,xe,ye;
    cin>>xs>>ys>>xe>>ye;
    s=(point){xs,ys},t=(point){xe,ye};
    int n;
    cin>>n;
    vector<int> v1,v2;
    vector<point> a(n+1);
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        if(det(a[i]-s,t-s)>0) v1.push_back(i);
        else if(det(a[i]-s,t-s)<0) v2.push_back(i);
        else{
            if(dot(a[i]-s,t-s)>0) r++;
            else l++;
        }
    }
    auto solve = [&](vector<int> p){
        vector<int> q=p;
        auto cmp= [&](int i,int j){
            long long res=det(a[i]-s,a[j]-s);
            if(res==0) return det(a[i]-t,a[j]-t)<0;
            else return res>0;
        };
        for(int i=0;i<2;i++){
            sort(p.begin(),p.end(),cmp);
            swap(p,q),swap(s,t);
        }
        return count_nixu(p,q);
    };
    long long ans=l*(l-1)/2+r*(r-1)/2+solve(v1)+solve(v2);
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}