#include <bits/stdc++.h>
#define int long long

std::map<long long,int> b;

std::vector<std::pair<int,int> > vec;
int ans=0;
void dfs(int idx,int res){
    //std::cout<<"DFS"<<idx<<' '<<res<<'\n';
    if(res>1e6) return;
    if(idx==vec.size()){
        //std::cout<<res<<'\n';
        ans+=b[res];
        return;
    }
    long long ress=1;
    for(int i=0;i<=vec[idx].second*2;i++){
        dfs(idx+1,res*ress);
        ress*=vec[idx].first;
    }
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin>>n;
    std::vector<int> a(n+1);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=n;i>=1;i--){
        //std::cin>>a[i];
        b[a[i]]++;
        std::map<int,int> ma;
        vec.clear();
        for(int j=2;j<=a[i]/j;j++){
            while((a[i]%j)==0){
                a[i]/=j;
                ma[j]+=1;
            }
        }
        if(a[i]!=1) ma[a[i]]+=1;
        //std::cout<<"CCF"<<i<<' '<<a[i]<<'\n';
        for(auto [c,d]:ma){
            //std::cout<<c<<' '<<d<<'\n';
            vec.push_back({c,d});
        }
        dfs(0,1);
        //std::cout<<ans<<'\n';
    }
    std::cout<<ans-n<<'\n';
}