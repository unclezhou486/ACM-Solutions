#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n;
int a[N][N];

map<int,int> ma1,ma2;
int cnt1,cnt2;
pair<int,int> s1[N],s2[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=1;j<=n;j++){
            res+=a[i][j];
        }
        if(!ma1.count(res)){
            ma1[res]=++cnt1;
            s1[cnt1]={res,i};
        }
    }
    //cout<<cnt2<<'\n';
    for(int j=1;j<=n;j++){
        int res=0;
        for(int i=1;i<=n;i++){
            res+=a[i][j];
        }
        if(!ma2.count(res)){
            ma2[res]=++cnt2;
            s2[cnt2]={res,j};
        }
    }
    //cout<<cnt2<<'\n';
    sort(s1+1,s1+1+cnt1);
    sort(s2+1,s2+1+cnt2);
    //cout<<cnt1<<'\n';
    int r1,c1,r2,c2;
    if(cnt1==1){
        int a1=s2[1].second;
        int a2=s2[3].second;
        //cout<<a1<<' '<<a2<<'\n';
        int res1=0,res2=0;
        for(int i=1;i<=n;i++){
            res1+=a[i][a1];
            res2+=a[i][a2];
        }
        for(int i=1;i<=n;i++){
            if(res1+a[i][a2]-a[i][a1]==res2-a[i][a2]+a[i][a1]){
                r1=i,c1=a1;
                r2=i,c2=a2;
                break;
            }
        }
    }
    else if(cnt2==1){
        int b1=s1[1].second;
        int b2=s1[3].second;
        //cout<<b1<<' '<<b2<<'\n';
        int res1=0,res2=0;
        for(int j=1;j<=n;j++){
            res1+=a[b1][j];
            res2+=a[b2][j];
        }
        for(int j=1;j<=n;j++){
            if(res1-a[b1][j]+a[b2][j]==res2-a[b2][j]+a[b1][j]){
                r1=b1,c1=j;
                r2=b2,c2=j;
                break;
            }
        }
    }
    else{     
        int b1=s1[1].second;
        int b2=s1[3].second;
        int a1=s2[1].second;
        int a2=s2[3].second;
        r1=b1,c1=a1;
        r2=b2,c2=a2;
        int res1=0,res2=0;
        for(int i=1;i<=n;i++){
            res1+=a[i][c1];
            res2+=a[i][c2];
        }
        if(res1-a[r1][c1]+a[r2][c2]!=res2-a[r2][c2]+a[r1][c1]){
            r1=b1,c1=a2;
            r2=b2,c2=a1;
        }
    }
    if(r1>r2){
        swap(r1,r2);
        swap(c1,c2);
    }
    else if(r1==r2){
        if(c1>c2){
            swap(r1,r2);
            swap(c1,c2);
        }
    }
    cout<<r1<<' '<<c1<<'\n'<<r2<<' '<<c2<<'\n';
}