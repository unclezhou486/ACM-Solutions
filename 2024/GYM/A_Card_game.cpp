#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;

char c[N];
int id[N];
int a[N];
int ans=0;

int f[N];

int lis(){
    int res=0;
    //for(int i=0;i<=n;i++) f[i]=1e9;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(f+1,f+1+res,a[i])-f;
        f[pos]=a[i];
        res=max(res,pos);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>id[i];
    }
    ans=n-1;
    char ch[6]="ERSWC";
    do{
        //cout<<ch<<'\n';
        for(int i=1;i<=n;i++){
            for(int j=0;j<5;j++){
                if(c[i]==ch[j]){
                    a[i]=j*n+id[i];
                }
            }
        }
        ans=min(ans,n-lis());
    }while(next_permutation(ch,ch+4));
    cout<<ans<<'\n';
}