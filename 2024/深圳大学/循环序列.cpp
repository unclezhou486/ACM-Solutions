#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+10;

int n,q;
int a[N];

map<int,int> ma;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma[a[i]]+=1;
    }
    while(q--){
        int l,r,t;
        cin>>l>>r>>t;
        int res1=0;
        if((r-1)/n>(l-1)/n){
            res1=(r-1)/n-(l-1)/n-1;
            res1*=ma[t];
            for(int i=l;i<=((l-1)/n+1)*n;i++){
                int d=i%n;
                if(!d) d=n;
                if(a[d]==t){
                    res1++;
                }
            }
            for(int i=((r-1)/n)*n+1;i<=r;i++){
                int d=i%n;
                if(!d) d=n;
                if(a[d]==t){
                    res1++;
                }
            }

        }
        else{
            for(int i=l;i<=r;i++){
                int d=i%n;
                if(!d) d=n;
                if(a[d]==t) res1++;
            }
        }
        res1=res1*(res1-1)/2;
        cout<<res1<<'\n';
    }
}