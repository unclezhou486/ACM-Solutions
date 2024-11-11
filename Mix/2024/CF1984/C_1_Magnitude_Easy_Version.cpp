#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long> a(4,0);
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        long long max1=-1,max2=1,min1=-1,min2=1;//1 +,2 -
        for(int i=0;i<4;i++){
            if(a[i]==-1e18) continue;
            long long y=a[i]+x;
            if(y>=0){
                if(max1==-1||max1<y) max1=y;
                if(min1==-1||min1>y) min1=y;
            }
            else{
                if(max2==1||y>max2) max2=y;
                if(min2==1||y<min2) min2=y;
            }
            y=std::abs(a[i]+x);
            //cout<<y<<' ';
            if(y>=0){
                if(max1==-1||max1<y) max1=y;
                if(min1==-1||min1>y) min1=y;
            }
            else{
                if(max2==1||y>max2) max2=y;
                if(min2==1||y<min2) min2=y;
            }
        }
        a[0]=max1;if(max1==-1) a[0]=-1e18;
        a[1]=min1;if(min1==-1) a[1]=-1e18;
        a[2]=max2;if(max2==1) a[2]=-1e18;
        a[3]=min2;if(min2==1) a[3]=-1e18;
    }
    cout<<max({a[0],a[1],a[2],a[3]})<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}