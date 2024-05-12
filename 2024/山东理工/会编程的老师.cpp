#include <bits/stdc++.h>

//P,Q,Y,S,Z,T,M,N,B



int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n,m;
    std::cin>>n>>m;
    //std::vector<char> str(n+1);
    std::string str;
    std::cin>>str;
    str=' '+str;
    std::map<char,int> ma;
    int cnt=0;
    for(int i=1;i<=n;i++){
        //std::cin>>str[i];
        if(ma.count(str[i])) continue;
        else{
            ma[str[i]]=++cnt;
        }
    }
    for(int i=1;i<=m;i++){
        std::string s;
        std::cin>>s;
        std::vector<int> vec(10,0);
        std::vector<int> vis(10,0);
        for(auto v:s){
            vis[ma[v]]=1;
        }
        //for(auto v:vis) std::cout<<v<<' ';
        std::vector<int> vecc(10,0);
        std::map<std::vector<int>,int> maa;
        int ans=0;
        maa[vecc]=0;
        for(int j=1;j<=n;j++){
            //std::cout<<ma[str[j]];
            //if(i==3&&j==7)return 0;
            if(vis[ma[str[j]]]){
                vecc[ma[str[j]]]+=1;
                maa[vecc]=j;
            }
            std::vector<int> veccc=vecc;
            bool fl=1;
            for(auto v:s){
                if(!veccc[ma[v]]) {fl=0;break;}
                else{
                    veccc[ma[v]]--;
                }
            }
            
            if(!fl) continue;
            if(maa.count(veccc))ans=std::max(ans,j-maa[veccc]);
            
        }
        std::cout<<ans<<'\n';
    }
}