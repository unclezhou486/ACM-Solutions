#include <bits/stdc++.h>

using namespace std;

int n;

int a[100000];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool fl=0;
    int res;
    while(!fl){
        fl=1;
        res++;
        for(int i=1;i<n;i++){
            if(a[i+1]<a[i]){
                swap(a[i+1],a[i]);
            }
        }
        for(int i=n-1;i>=1;i--){
            if(a[i+1]<a[i]){
                swap(a[i+1],a[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i+1]<a[i]) fl=0;
        }
    }
    cout<<res<<'\n';
}