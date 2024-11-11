#include <iostream>

using namespace std;

const int N=510;

char a[N][N];

int n,m;

bool check(int x,int y){
    if(x>0&&x<=n&&y>0&&y<=m&&a[x][y]=='#') return 1;
    else return 0;
}

int x1[10]={0,0,0,1,1,2,2,2,3,4};
int y1[10]={0,1,2,0,2,0,1,2,0,0};

int x2[8]={0,0,0,1,2,2,3,4};
int y2[8]={0,1,2,2,1,2,2,2};

int x3[13]={0,0,0,1,1,2,2,2,3,3,4,4,4};
int y3[13]={0,1,2,0,2,0,1,2,0,2,0,1,2};

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int res1,res2,res3;
    res1=res2=res3=0;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(a[i][j]=='#'){
                bool fl=1;
                
                
                for(int k=0;k<13;k++){
                    if(!check(i+x3[k],j+y3[k])) fl=0;
                }
                if(fl){
                    res3++;
                    for(int k=0;k<13;k++){
                        a[i+x3[k]][j+y3[k]]='.';
                    }
                    continue;
                }for(int k=0;k<8;k++){
                    if(!check(i+x2[k],j+y2[k])) fl=0;
                }
                
                fl=1;
                for(int k=0;k<10;k++){
                    if(!check(i+x1[k],j+y1[k])) fl=0;
                }
                if(fl){
                    res1++;
                    for(int k=0;k<10;k++){
                        a[i+x1[k]][j+y1[k]]='.';
                    }
                    continue;
                }
                fl=1;
                if(fl){
                    res2++;
                    for(int k=0;k<8;k++){
                        a[i+x2[k]][j+y2[k]]='.';
                    }
                    continue;
                }
                //fl=1;
            }
            //cout<<res1<<' ';
        }
        //cout<<'\n';
    }
    cout<<res1<<' '<<res2<<' '<<res3<<'\n';
}