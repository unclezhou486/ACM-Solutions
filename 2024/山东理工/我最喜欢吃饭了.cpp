#include <bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n,m;
    std::cin>>n>>m;
    std::vector<int> vec;
    
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        vec.push_back(x);
    }
    int ans=0;
    while(vec.size()){
        std::vector<int> vecc;
        int minn=vec[0];
        //vecc.push_back(minn);
        for(int i=1;i<vec.size();i++){
            if(vec[i]>minn){
                minn=vec[i];
            }
            else{
                vecc.push_back(vec[i]);
            }
        }
        vec=vecc;
        ans++;
    }
    if(ans<=m) std::cout<<"Karashi cblcd";
    else std::cout<<"Karashi lovelove";
}