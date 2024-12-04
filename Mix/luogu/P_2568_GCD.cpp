#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N=1e7+10;

int phi[N];
long long pre[N];
vector<int> pri;
bool not_pri[N];
int n;
void shai(){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!not_pri[i]){
            phi[i]=i-1;
            pri.push_back(i);
        }
        for(auto pri_j:pri){
            if(1ll*i*pri_j>n) break;
            not_pri[i*pri_j]=1;
            if(i%pri_j==0){
                phi[i*pri_j]=phi[i]*pri_j;
                break;
            }
            phi[i*pri_j]=phi[i]*phi[pri_j];
        }
    }
}
long long ans=0;
int main(){
    cin>>n;
    shai();
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+phi[i];
    for(auto pri_j:pri){
        ans=ans+2*pre[n/pri_j]-1;
    }
    cout<<ans<<'\n';
}