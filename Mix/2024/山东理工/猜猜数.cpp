#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> vec;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++) vec.push_back((i<<16|j));
    }
    auto cal = [&] (int op,int a,int b) -> int {
        if(op) return a+b;
        else return a*b;
    };

    auto work = [&] (int op,int cmp) -> void {
        std::vector<int> vecc;
        for(auto u:vec){
            int cnt=0,res=cal(op,(u>>16),u&0xFFFF);
            for(auto v:vec){
                if(cal(op,v>>16,v&0xFFFF)==res){
                    vecc.push_back(v),cnt++;
                }
            }
            if(!cmp){
                if(cnt<=1){
                    while(cnt--) vecc.pop_back();
                }
            }
            else{
                if(cnt!=1){
                    while(cnt--) vecc.pop_back();
                }
            }
        }
        std::sort(vecc.begin(),vecc.end());
        vecc.erase(unique(vecc.begin(),vecc.end()),vecc.end());
        std::swap(vec,vecc);
    };
    work(0,0);
    work(1,0);
    work(0,1);
    work(1,1);
    if(vec.size()){
        std::cout<<vec.size()<<":";
        for(auto x:vec){
            std::cout<<"("<<(x>>16)<<','<<(x & 0xFFFF)<<") " ;
        }
    }
    else{
        std::cout<<"AHa?";
    }
    std::cout<<'\n';
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