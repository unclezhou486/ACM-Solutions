#include <bits/stdc++.h>

using namespace std;
typedef double LD;

const LD eps=1e-9;
const int N=2e5+10;
int t;

int n,k;

struct point{
    LD x,y;
    point operator +(const point &a) const{
        return {x+a.x,y+a.y};
    }
    point operator -(const point &a) const{
        return {x-a.x,y-a.y};
    }
};

LD dot(point &a,point &b){
    return a.x*b.x+a.y*b.y;
}

LD det(point a,point b){
    return a.x*b.y-a.y*b.x;
}

int sgn(LD x){
    return (x>eps) ?1:(x<-eps?-1:0);
}

point a[N];

//void change(int &j,point b,point c){
//    while(j>0&&sgn(abs(det(a[j-1]-b,a[j-1]-c))-abs(det(a[j]-b,a[j]-c)))==1){
//        j--;
//    }
//    while(j<2*n&&sgn(abs(det(a[j+1]-b,a[j+1]-c))-abs(det(a[j]-b,a[j]-c)))==1){
//        cout<<abs(det(a[j+1]-b,a[j+1]-c))<<' '<<abs(det(a[j]-b,a[j]-c))<<'\n';
//        j++;
//    }
//    return;
//    //while(sgn(abs));
//}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y;
            a[i+n]=a[i];
        }
        LD ans=0;
        LD sq=0;
        for(int i=2;i<=k;i++){
            sq+=0.5*abs(det(a[1]-a[i],a[1]-a[i+1]));
            //cout<<sq<<' ';
        }
        int j=k+2;
        LD res=0.5*abs(det(a[1]-a[j],a[j]-a[k+1]));
        for(int i=k+2;i<=n;i++){
            if(res<0.5*abs(det(a[1]-a[i],a[i]-a[k+1]))){
                res=0.5*abs(det(a[1]-a[i],a[i]-a[k+1]));
                j=i;
            }
        }
        ans=max(ans,res+sq);
        //cout<<j<<'\n';
        for(int i=2;i<=n;i++){
            sq-=0.5*abs(det(a[i+k-1]-a[i],a[i+k-1]-a[i-1]));
            sq+=0.5*abs(det(a[i+k]-a[i],a[i+k-1]-a[i]));
            point b=a[i],c=a[i+k];
            if(j<i+k+1) j++;
                while(j>i+k+1&&sgn(abs(det(a[j-1]-b,a[j-1]-c))-abs(det(a[j]-b,a[j]-c)))==1){
                    j--;
                }
                while(j<i+n-1&&sgn(abs(det(a[j+1]-b,a[j+1]-c))-abs(det(a[j]-b,a[j]-c)))==1){
                    //cout<<abs(det(a[j+1]-b,a[j+1]-c))<<' '<<abs(det(a[j]-b,a[j]-c))<<'\n';
                    j++;
                }
                //cout<<j<<'\n';
                //return;
            //change(j,a[i],a[i+k+1]);
            res=0.5*abs(det(a[i]-a[j],a[i+k]-a[j]));
            //cout<<res<<' '<<sq<<' '<<j<<'\n';
            ans=max(ans,res+sq);
        }
        cout<<fixed<<setprecision(9)<<ans<<'\n';
    }
}
/*
1
7 5
-999999980 -999999988
-999999979 -999999984
-999999978 -999999978
-999999979 -999999972
-1000000000 -999999998
-999999993 -1000000000
-999999984 -999999993
*/