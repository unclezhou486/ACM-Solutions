#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n;
int a[N];

bool check(int x,int y){
    int res=0;
    res=x;
    if(y==10) res*=100;
    else res*=10;
    res+=y;
    if(res%36) return 0;
    else return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(check(a[j],a[i]))ans++;
            if(check(a[i],a[j]))ans++;
        }
    }
    cout<<ans<<'\n';
}