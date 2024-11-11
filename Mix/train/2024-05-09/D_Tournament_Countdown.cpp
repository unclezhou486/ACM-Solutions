#include <bits/stdc++.h>

using namespace std;

int query(int x,int y){
    cout<<"? "<<x<<' '<<y<<endl;
    int res;
    cin>>res;
    return res;
}

void answer(int x){
    cout<<"! "<<x<<endl;
}

void solve(){
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=1;i<=(1<<n);i++){
        vec.push_back(i);
    }
    while(vec.size()>2){
        vector<int> res;
        n=vec.size();
        for(int i=0;i<n;i+=4){
            int a=vec[i],b=vec[i+1],c=vec[i+2],d=vec[i+3];
            int ress=query(a,c);
            //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
            if(ress==0){
                if(query(b,d)==1)res.push_back(b);
                else res.push_back(d);
            }
            else if(ress==1){
                if(query(a,d)==1) res.push_back(a);
                else res.push_back(d);
            }
            else{
                if(query(b,c)==1) res.push_back(b);
                else res.push_back(c);
            }
        }
        vec=res;
    }
    if(vec.size()==1){
        answer(vec[0]);
        return;
    }
    else{
        if(query(vec[0],vec[1])==1)answer(vec[0]);
        else answer(vec[1]);
    }
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