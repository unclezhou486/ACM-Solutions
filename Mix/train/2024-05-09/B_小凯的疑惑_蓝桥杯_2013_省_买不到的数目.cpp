#include <bits/stdc++.h>

using namespace std;

long long a,b;

bool ok(int x){
    for(int j=0;j<=1000;j++){
        if(j*a>x) break;
        if((x-j*a)%b==0){
            return 1;
        }
    }
    return 0;
}

bool check(){
    for(int i=2;i<=a;i++){
        if((b%i)==0) return 0;
    }
    return 1;
}

int main(){
    //freopen("1.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(0);
    //for(a=2;a<=100;a++){
    //    for(b=a+1;b<=100;b++){
    //        if(check()){
    //            int k;
    //            for(k=1000;k>=1;k--){
    //                if(!ok(k)) break;
    //            }
    //            if(k){
    //                cout<<a<<' '<<b<<' '<<k<<'\n';
    //            }
    //        }
    //    }
    //}
    //long long a,b;
    cin>>a>>b;
    cout<<a*b-a-b<<'\n';
    return 0;
}