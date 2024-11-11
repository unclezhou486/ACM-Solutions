#include <bits//stdc++.h>

using namespace std;

const int N=110;

int n;

int a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        if(str=="byl") a[i]=1;
        a[i]+=a[i-1];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(2*(a[i]-a[j-1])>(i-j+1)){
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
}