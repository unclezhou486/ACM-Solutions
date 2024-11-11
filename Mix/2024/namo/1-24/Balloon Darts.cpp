#include <bits/stdc++.h>

using namespace std;
typedef long long LD;
const int N=1e4+10;
//const LD eps=1e-9;

struct point{
    LD x,y;
    point operator +(const point &a) const{
        return {x+a.x,y+a.y};
    }
    point operator -(const point &a) const{
        return {x-a.x,y-a.y};
    }
};

LD det(point a,point b){
    return a.x*b.y-b.x*a.y;
}


int n;
vector<point> a;
//int cnt=0;
bool sou(vector<point> b,int k){
    int m=b.size();
    //if(cnt==1){
    //    for(int i=0;i<m;i++){
    //        cout<<b[i].x<<' '<<b[i].y<<'\n';
    //    }
    //}
    //cnt++;
    if(m<=2*k) return 1;
    for(int i=0;i<=k;i++){
        for(int j=i+1;j<=k;j++){
            vector<point> res;
            for(int q=0;q<m;q++){
                if(det(b[q]-b[i],b[q]-b[j])!=0){
                    res.push_back(b[q]);
                }
            }
            if(sou(res,k-1)) return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        LD x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    if(sou(a,3)){
        cout<<"possible\n";
    }
    else cout<<"impossible\n";
}