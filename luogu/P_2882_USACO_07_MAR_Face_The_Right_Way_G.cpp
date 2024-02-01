#include <bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int n,a[N];
int b[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='B') a[i]=0;
        else a[i]=1;
    }
    int ansk,anss;
    anss=1e9;
    for(int i=1;i<=n;i++){
        bool fl=1;
        int res=0;
        for(int j=1;j<=n;j++){
            b[j]=0;
        }
        for(int j=1;j<=n;j++){
            b[j]+=b[j-1];
            if((a[j]^(b[j]%2))) continue;
            else{
                int l=j,r=j+i-1;
                if(r>n){
                    fl=0;break;
                }
                res++;
                b[l]++;
                b[r+1]--;
            }
        }
        if(fl){
            if(anss>res){
                anss=res;
                ansk=i;
            }
        }
    }
    cout<<ansk<<' '<<anss<<'\n';
}