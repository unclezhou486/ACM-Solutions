#include <bits/stdc++.h>

using namespace std;

void solve(){

}

int main(){
        struct timeb timer;
        ftime(&timer);
    srand(timer.time*1000+timer.millitm);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=10;
    cout<<t<<'\n';
    // cin>>t;
    while(t--){
        int n=(rand()%10)+1,k=(rand()%32)+1;
        cout<<n<<' '<<k<<'\n';
        for(int i=1;i<=n;i++){
            int x=rand()%100+1;
            cout<<x<<" \n"[i==n];
        }
    }
    return 0;
}