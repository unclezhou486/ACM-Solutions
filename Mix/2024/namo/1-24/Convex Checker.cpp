#include <bits/stdc++.h>

using namespace std;
typedef double LD;

const LD eps=1e-6;
const int N=2e5+10;

int n;

struct point{
    LD x,y;
    point operator + (const point &a) const{
        return {x+a.x,y+a.y};
    }
    point operator - (const point &a) const{
        return {x-a.x,y-a.y};
    }
    point operator * (LD a) const{
        return {x*a,y*a};
    }
};

struct line{
    point s,t;
};

LD dot (const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}

LD det (const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}

LD sqr(LD a){
    return a*a;
}

LD dis (const point &a){
    return (sqrt(sqr(a.x)+sqr(a.y)));
}

int sgn(LD x){
    return x>eps?1:(x<-eps?-1:0);
}

point a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    LD t=0;
    a[1+n]=a[1];
    a[2+n]=a[2];
    for(int i=1;i<=n;i++){
        //line u,v;
        point u=a[i+1]-a[i];
        point v=a[i+2]-a[i+1];
        if(det(u,v)==0){
            cout<<"No\n";
            return 0;
        }
        t+=(acos(dot(u,v)/dis(u)/dis(v)));
    }
    //cout<<t<<'\n';
    if(sgn(t-2*acos(-1))==0){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    //cout<<t<<'\n';
}