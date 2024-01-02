#include <bits/stdc++.h>

using namespace std;

const int N=1e2+10;

int t;
int n;
int a[N],b[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        bool fl=1;
        for(int i=n;i>=1;i--){
            if(a[i]<b[i]) {fl=0;break;}
        }
        cout<<(fl?"YES\n":"NO\n");
    }
}