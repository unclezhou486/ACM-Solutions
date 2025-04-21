#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr double inf = 4e18;

struct node{
    int x,y;
    node operator -(const node &a) const{
        return (node){x-a.x,y-a.y};
    }
};

struct line{
    node s,t;
};

double to_x(node a,node b){
    if(b.y>=a.y){
        return inf;
    }
    return 1.0*a.x-1.0*a.y*(1.0*(a.x-b.x)/(a.y-b.y));
}

int dot(node a,node b){
    return a.x*b.x+a.y*b.y;
}

int det(node a,node b){
    return a.x*b.y-a.y*b.x;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<node> a(n+10);
    vector<line> b(m+10);
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=m;i++){
        cin>>b[i].s.x>>b[i].s.y>>b[i].t.x>>b[i].t.y;
        if(b[i].s.y>b[i].t.y){
            swap(b[i].s,b[i].t);
        }
    }
    vector<tuple<double,int,int> > vec;
    int cnt=n;
    for(int i=1;i<=n;i++){
        bool flag=true;
        vector<pair<double,int> > vecc;
        for(int j=1;j<=m;j++){
            if(det(a[i]-b[j].s,a[i]-b[j].t)==0&&(dot(a[i]-b[j].s,a[i]-b[j].t)<=0)){
                flag=false;
                cnt--;
                break;
            }
            double x1=to_x(a[i],b[j].s);
            double x2=to_x(a[i],b[j].t);
            if(x1==inf&&x2==inf){
                continue;
            }
            else if(x1==inf){
                if(det(a[i]-b[j].s,a[i]-b[j].t)<0) x1=-inf;
                else x1=inf;
            }
            else if(x2==inf){
                if(det(a[i]-b[j].s,a[i]-b[j].t)<0) x2=-inf;
                else x2=inf;
            }
            if(x1>x2) swap(x1,x2);
            vecc.push_back({x1,1});
            vecc.push_back({x2,-1});
        }
        if(flag){
            for(auto [xnum,val]:vecc){
                vec.push_back({xnum,val,i});
            }
        }
    }
    sort(vec.begin(),vec.end());
    double ans=0;
    double pre=-inf;
    int nowcnt=0;
    vector<int> cntt(n+10);
    for(auto x:vec){
        auto [xnum,val,i]=x;
        if(nowcnt==cnt){
            ans+=xnum-pre;
        }
        if(val==1){
            if(!cntt[i]) nowcnt+=1;
        }
        else{
            if(cntt[i]==1) nowcnt-=1;
        }
        cntt[i]+=val;
        pre=xnum;
    }
    if(!cnt||ans>1e9){
        cout<<-1<<'\n';
    }
    else{
        cout<<fixed<<setprecision(10)<<ans<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}