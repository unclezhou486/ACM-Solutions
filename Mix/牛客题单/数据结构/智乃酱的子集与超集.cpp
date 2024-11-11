#include <bits/stdc++.h>

using namespace std;

const int N=21;


//int a[1<<N];
int b[N];

long long dp1[1<<N],dp2[1<<N];

int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            if(j&(1<<i)){
                dp1[j]^=b[i];
                dp2[j]^=b[i];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=(1<<n)-1;j>=0;j--){
            if(j&(1<<i))dp1[j]+=dp1[j^(1<<i)];
            else dp2[j]+=dp2[j^(1<<i)];
        }
    }

    while(m--){
        int x;
        cin>>x;
        int res=0;
        while(x--){
            int y;
            cin>>y;
            y--;
            res+=(1<<y);
        }
        cout<<dp1[res]<<' '<<dp2[res]<<'\n';
    }
}