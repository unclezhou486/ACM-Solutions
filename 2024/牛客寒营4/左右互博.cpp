#include <bits/stdc++.h>

using namespace std;

int n,a;
long long sum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        sum+=a;
        sum+=1;
    }
    if(sum%2){
        cout<<"gui\n";
    }
    else cout<<"sweet\n";
}