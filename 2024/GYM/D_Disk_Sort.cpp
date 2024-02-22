#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n;
int cnt;
int a[4][N];
bool v[N];
queue<pair<int,int> > q;

bool check(){
    for(int i=1;i<=n+1;i++){
        if(v[i]) continue;
        if(!a[1][i]) continue;
        if(a[1][i]==a[2][i]&&a[2][i]==a[3][i]){
            v[i]=1;
            cnt++;
        }
        else{
            v[i]=0;
        }
    }
    if(cnt==n) return 1;
    else return 0;
}

struct node{
    int x,y;
};

bool cmp(node a,node b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    else return a.x<b.x;
}

bool cmp1(node a,node b){
    return a.y<b.y;
}

void meow(int x,int i,int y,int j){
    swap(a[i][x],a[j][y]);
    q.push({x,y});
}
bool fuck=0;
void ccf(int p){
    int x=a[1][p];
    node c[4];
    int res=0;
    int D=0;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n+1;j++){
            if(a[i][j]==x){
                c[++res]={j,i};
            }
        }
    }
    for(int i=1;i<=n+1;i++){
        if(!a[1][i]) {D=i;break;}
    }
    sort(c+1,c+1+3,cmp);
    if(c[2].x==c[3].x){
        swap(c[1],c[3]);
        swap(c[2],c[1]);
    }
    if(c[1].x==c[2].x){
        int A=c[1].x,B=c[3].x;
        if(c[1].y==1&&c[2].y==2&&c[3].y==1){
            meow(B,1,D,3);
            meow(A,1,D,2);
            meow(A,2,D,1);
            meow(A,3,B,1);
        }
        else if(c[1].y==1&&c[2].y==2&&c[3].y==2){
            meow(A,1,D,3);
            meow(A,2,D,2);
            meow(B,1,A,2);
            meow(B,2,D,1);
            meow(B,3,A,1);
        }
        else if(c[1].y==1&&c[2].y==2&&c[3].y==3){
            meow(B,1,D,3);
            meow(B,2,D,2);
            meow(A,1,B,2);
            meow(A,2,B,1);
            meow(A,3,D,1);
        }
        else if(c[1].y==1&&c[2].y==3&&c[3].y==1){
            meow(A,1,D,3);
            meow(B,1,D,2);
            meow(A,2,B,1);
            meow(A,3,D,1);
        }
        else if(c[1].y==1&&c[2].y==3&&c[3].y==2){
            meow(A,1,D,3);
            meow(B,1,A,1);
            meow(B,2,D,2);
            meow(A,1,B,2);
            meow(A,2,B,1);
            meow(A,3,D,1);
        }
        else if(c[1].y==1&&c[2].y==3&&c[3].y==3){
            meow(B,1,D,3);
            meow(B,2,D,2);
            meow(A,1,B,2);
            meow(A,2,D,1);
            meow(A,3,B,1);
        }
        else if(c[1].y==2&&c[2].y==3){
            meow(A,1,D,3);
            meow(B,1,A,1);
            meow(D,3,B,1);
        }
        //for(int i=1;i<=3;i++){
        //    for(int j=1;j<=n+1;j++){
        //        cout<<a[i][j]<<' ';
        //    }
        //    cout<<'\n';
        //}
        //fuck=1;
        //return;
    }
    else{
        sort(c+1,c+1+3,cmp1);
        int A=c[1].x,B=c[2].x,C=c[3].x;
        if(c[1].y==1&&c[2].y==1&&c[3].y==1){
            meow(B,1,D,3);
            meow(A,1,D,2);
            meow(C,1,D,1);
            meow(C,2,A,1);
            meow(C,3,B,1);
        }
        else if(c[1].y==1&&c[2].y==1&&c[3].y==2){
            meow(B,1,D,3);
            meow(A,1,D,2);
            meow(C,1,A,1);
            meow(C,2,D,1);
            meow(C,3,B,1);
        }
        else if(c[1].y==1&&c[2].y==1&&c[3].y==3){
            meow(B,1,D,3);
            meow(A,1,D,2);
            meow(C,1,A,1);
            meow(C,2,B,1);
            meow(C,3,D,1);
        }
        else if(c[1].y==1&&c[2].y==2&&c[3].y==2){
            meow(A,1,D,3);
            meow(B,1,A,1);
            meow(B,2,D,2);
            meow(C,1,B,2);
            meow(C,2,D,1);
            meow(C,3,B,1);
        }
        else if(c[1].y==1&&c[2].y==2&&c[3].y==3){
            meow(C,1,D,3);
            meow(C,2,D,2);
            meow(A,1,C,2);
            meow(B,1,D,1);
            meow(B,2,C,1);
            meow(B,3,A,1);
        }
        else if(c[1].y==1&&c[2].y==3&&c[3].y==3){
            meow(C,1,D,3);
            meow(C,2,D,2);
            meow(A,1,C,2);
            meow(B,1,A,1);
            meow(B,2,D,1);
            meow(B,3,C,1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    bool fl=1;
    while(1){
        //if(fuck) break;
        if(check()) break;
        for(int i=1;i<=n+1;i++){
            if(!v[i]&&a[1][i]){
                ccf(i);
                break;
            }
        }
    }
    int D=0;
    for(int i=1;i<=n+1;i++){
        if(!a[1][i]) {D=i;break;}
    }
    if(D!=n+1){
        meow(n+1,1,D,3);
        meow(n+1,2,D,2);
        meow(n+1,3,D,1);
    }
    cout<<q.size()<<'\n';
    while(q.size()){
        cout<<q.front().first<<' '<<q.front().second<<'\n';
        q.pop();
    }
}