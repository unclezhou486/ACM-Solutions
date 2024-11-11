#include <bits/stdc++.h>

using namespace std;

const int N=4e5+10;

int n,m;
int ans[N];
int st[N][20];
struct line{
    int l,r,id;
}a[N];

bool cmp(line a,line b){
    return a.l<b.l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        if(a[i].r<a[i].l)a[i].r+=m;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        a[i+n].l=a[i].l+m;
        a[i+n].r=a[i].r+m;
    }
    for(int i=1,j=1;i<=2*n;i++){
        while(j<=2*n&&a[j].l<=a[i].r){
            j++;
        }
        st[i][0]=j-1;
    }
    for(int i=1;i<=19;i++){
        for(int j=1;j<=2*n;j++){
            st[j][i]=st[st[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=n;i++){
        int lim=a[i].l+m;
        int res=0;
        int pos=i;
        for(int j=19;j>=0;j--){
            if(st[pos][j]&&a[st[pos][j]].r<lim){
                res+=(1<<j);
                pos=st[pos][j];
            }
        }
        ans[a[i].id]=res+2;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}