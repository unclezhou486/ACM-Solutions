#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

struct node{
    int x,y;
}a[N];

struct line{
    int x,y;
    int len;
}b[N];

bool cmp(line a,line b){
    return a.x*b.y>a.y*b.x;
}

int dot(line a,line b){
    return a.x*b.x+a.y*b.y;
}

int det(line a,line b){
    return a.x*b.y-a.y*b.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        map<int,int> ma;
        deque<line> q; 
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            b[++cnt].x=a[j].x-a[i].x;
            b[cnt].y=a[j].y-a[i].y;
            b[cnt].len=(b[cnt].x*b[cnt].x+b[cnt].y*b[cnt].y);
        }
        int m=n-1;
        sort(b+1,b+1+m,cmp);
        for(int j=1;j<=m;j++){
            for(int k=1;k<j;k++){
                if(dot(b[j],b[k])<0&&det(b[j],b[k])){
                    if(b[j].len==b[k].len) ans++;
                }
            }
        }
    }
    cout<<ans<<'\n';
    //ans=-ans;
    //for(int i=1;i<=n;i++){
    //    map<int,int> ma;
    //    int cnt=0;
    //    for(int j=1;j<=n;j++){
    //        if(i==j) continue;
    //        b[++cnt].x=a[j].x-a[i].x;
    //        b[cnt].y=a[j].y-a[i].y;
    //        b[cnt].len=(b[cnt].x*b[cnt].x+b[cnt].y*b[cnt].y);
    //        ans+=ma[b[cnt].len];
    //        ma[b[cnt].len]++;
    //    }
    //    ma.clear();
    //}
    //cout<<ans<<'\n';
}