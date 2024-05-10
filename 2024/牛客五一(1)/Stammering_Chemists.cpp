#include <bits/stdc++.h>

//using namespace std;

void solve(){
    std::vector<int> ru(6);
    std::map<std::pair<int,int>,int>ma;
    std::queue<int> q[4];
    for(int i=1;i<=5;i++){
        int a,b;
        std::cin>>a>>b;
        a--,b--;
        ru[a]++,ru[b]++;
        ma[{a,b}]=ma[{b,a}]=1;
    }
    for(int i=0;i<6;i++){
        q[ru[i]-1].push(i);
    }
    int i4=q[3].size(),i3=q[2].size(),i2=q[1].size(),i1=q[0].size();
    if(i4){
        std::cout<<"2,2-dimethylbutane\n";
    }
    else{
        if(i3==2){
            std::cout<<"2,3-dimethylbutane\n";
        }
        else if(i3==0){
            std::cout<<"n-hexane\n";
        }
        else{
            int x=q[1].front();q[1].pop();
            int y=q[1].front();
            if(ma[{x,y}]){
                std::cout<<"2-methylpentane\n";
            }
            else std::cout<<"3-methylpentane\n";
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}