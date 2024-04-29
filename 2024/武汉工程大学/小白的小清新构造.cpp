#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,k,s;

int a[N];
int b[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>s;
    if(k==1&&n!=1){
        cout<<"NO\n";
        return 0;
    }
    if(k%2){
        for(int i=1;i<=k;i++){
            if(i%2==1){
                b[i]=1;
                //sum+=1;
            }
            else{
                b[i]=2;
            }
        }
        if(k<n)b[k]=3;
        int sum=0;
        for(int i=1;i<=n;i++){
            int res=i%k;
            if(!res) res=k;
            a[i]=b[res];
            sum+=a[i];
        }
        if(sum<=s){
            cout<<"YES\n";
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }
            //return 0;
        }
        else cout<<"NO\n";
    }
    else{
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%2==1){
                a[i]=1;
                sum+=1;
            }
            else a[i]=2,sum+=2;
        }
        if(sum<=s){
            cout<<"YES\n";
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }

        }
        else cout<<"NO\n";
    }
}