#include <bits/stdc++.h>

using namespace std;


int a[100]={2,3,5,7,11,13,17,19,23,29,31,37};
int ans[110];
int main(){
    int l,r;
    cin>>l>>r;
    for(int i=0;i<12;i++){
        for(int j=i+1;j<12;j++){
            for(int k=j+1;k<12;k++){
                if(a[i]*a[j]*a[k]<=100){
                    ans[a[i]*a[j]*a[k]]=1;
                }
            }
        }
    }
    bool fl=1;
    int an=0;
    for(int i=l;i<=r;i++){
        if(ans[i]){
            an=i;
            fl=0;
        }
    }
    if(fl){
        cout<<-1<<'\n';
    }
    else cout<<an<<'\n';
}