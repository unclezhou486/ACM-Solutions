#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e5+10;

int n,a[N];

map<int,int> ma;

vector<int> ans;

//int ne[N];

map<int,pair<int,int> > ne;

bool check(int x,int y){//odd even
    if(y%2) swap(x,y);
    if(ma[y]){
        ma[y]--;
        if(ma[x]){
            ma[y]++;
            ne[x+y]={x,y};
            return 1;
        }
        else{
            if(x==1) {ma[y]++;return 0;}
            //ma[y]--;
            int xx=x/2,yy=x-x/2;
            if(yy%2) swap(xx,yy);
            if(check(xx,yy)){
                ma[y]++;
                ne[x+y]={x,y};
                ne[x]={xx,yy};
                return 1;
            }
            else{
                ma[y]++;
                return 0;
            }
        }
    }
    else{
        return 0;
    }
}

signed main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma[a[i]]++;
    }
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    //for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    for(int i=1;i<=n;i++){
        //cout<<i<<" ";
        if(!ma[a[i]]) continue;
        //cout<<i<<' '<<a[i]<<'\n';
        if(a[i]%2==0){
            //cout<<"CCF:";
            //cout<<i<<' '<<a[i]<<'\n';
            //for(auto [val,cnt]:ma){
            //    if(cnt)
                //cout<<val<<' '<<cnt<<'\n';
            //}
            ne.clear();
            if(check(a[i]+1,a[i])){
                int x,y;
                x=a[i]+1,y=a[i];
                while(x&&y){
                    //cout<<x<<" "<<y<<'\n';
                    //_sleep(500);
                    if(ma[x])ma[x]--;
                    if(ma[y])ma[y]--;
                    int res=x;
                    x=ne[res].first,y=ne[res].second;
                }
                //cout<<x+y<<'\n';
                //cout<<ne[9].first<<' '<<ne[9].second<<'\n';
                //cout<<ne[5].first<<' '<<ne[5].second<<'\n';
                //cout<<ne[3].first<<" "<<ne[2].second<<'\n';
                ans.push_back({a[i]+1+a[i]});
            }
            else if(check(a[i]-1,a[i])){
                    //cout<<"CCF:"<<a[i]-1<<' '<<a[i]<<'\n';
                int x,y;
                x=a[i]-1,y=a[i];
                while(x&&y){
                    //cout<<"CCF:"<<x<<' '<<y<<'\n';
                    if(ma[x])ma[x]--;
                    if(ma[y])ma[y]--;
                    int res=x;
                    x=ne[res].first,y=ne[res].second;
                }
                ans.push_back({a[i]-1+a[i]});                
            }
        }
    }
    for(auto [value,count]:ma){
        for(int i=0;i<count;i++){
            ans.push_back(value);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto v:ans){
        cout<<v<<' ';
    }
}