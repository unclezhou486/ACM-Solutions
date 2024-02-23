#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;
int a[N],b[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n);
    int ansi=0;
    int ansj=0;
    int ansx=1e9;
    for(int i=1;i<=n;i++){
        auto it=lower_bound(a+1,a+1+n,b[i])-a;
        //cout<<it<<'\n';
        if(abs(a[it]-b[i])<ansx){
            ansx=abs(a[it]-b[i]);
            ansi=it;
            ansj=i;
        }
        it--;
        if(it&&abs(a[it]-b[i])<ansx){
            ansx=abs(a[it]-b[i]);
            ansi=it;
            ansj=i;
        }
    }
    swap(a[ansi],a[ansj]);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
}