#include <bits/stdc++.h>

using namespace std;

const int N=5e2+10;

int h,w;
int H,W;

int a[N][N],b[N][N];

vector<pair<int,int> > aa,bb,c1,c2,d1,d2,bbb;

int rex,rey,tox,toy;

bool check(vector<pair<int,int> >a,vector<pair<int,int> >b ){
    vector<pair<int,int> > res;
    map<pair<int,int>,int> v;
    for(auto u:b){
        v[u]=1;
    }
    for(auto u:a){
        if(!(v.count(u))){
            res.push_back(u);
        }
        else{
            v[u]=0;
        }
    }
    if(res.size()==1){
        rex=res[0].first,rey=res[0].second;
        for(auto [x,y]:v){
            if(y){
                tox=x.first,toy=x.second;
                break;
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char x;
            cin>>x;
            if(x=='o') a[i][j]=1,aa.push_back({i,j});
            else a[i][j]=0;
        }
    }
    int n1=aa.size();
    for(int i=0;i<n1;i++){
        c1.push_back({aa[i].first-aa[0].first,aa[i].second-aa[0].second});
        c2.push_back({aa[i].first-aa[1].first,aa[i].second-aa[1].second});
    }
    cin>>H>>W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char x;
            cin>>x;
            if(x=='o'){
                b[i][j]=1;
                bb.push_back({i,j});
            }
            else{
                b[i][j]=0;
            }
        }
    }
    int n2=bb.size();
    for(int i=0;i<n2;i++){
        bbb.push_back({bb[i].first,bb[i].second});
        d1.push_back({bb[i].first-bb[0].first,bb[i].second-bb[0].second});
        d2.push_back({bb[i].first-bb[1].first,bb[i].second-bb[1].second});
    }
    if(check(c1,d1)||check(c1,d2)){
        cout<<rey+aa[0].second<<' '<<rex+aa[0].first<<'\n'<<toy+aa[0].second<<' '<<tox+aa[0].first<<'\n';
        return 0;
    }   
    else if(check(c2,d1)||check(c2,d2)){
        cout<<rey+aa[1].second<<' '<<rex+aa[1].first<<'\n'<<toy+aa[1].second<<' '<<tox+aa[1].first<<'\n';
        return 0;
    }
    for(int i=0;i<n2;i++){
        bbb[i].first=-bb[i].first;
        bbb[i].second=-bb[i].second;
    }
    sort(bbb.begin(),bbb.end());
    for(int i=0;i<n2;i++){
        d1[i].first=bbb[i].first-bbb[0].first;
        d1[i].second=bbb[i].second-bbb[0].second;
        d2[i].first=bbb[i].first-bbb[1].first;
        d2[i].second=bbb[i].second-bbb[1].second;        
    }
    if(check(c1,d1)||check(c1,d2)){
        cout<<rey+aa[0].second<<' '<<rex+aa[0].first<<'\n'<<toy+aa[0].second<<' '<<tox+aa[0].first<<'\n';
        return 0;
    }   
    else if(check(c2,d1)||check(c2,d2)){
        cout<<rey+aa[1].second<<' '<<rex+aa[1].first<<'\n'<<toy+aa[1].second<<' '<<tox+aa[1].first<<'\n';
        return 0;
    }
    for(int i=0;i<n2;i++){
        bbb[i].first=bb[i].second;
        bbb[i].second=-bb[i].first;
    }
    sort(bbb.begin(),bbb.end());
    for(int i=0;i<n2;i++){
        d1[i].first=bbb[i].first-bbb[0].first;
        d1[i].second=bbb[i].second-bbb[0].second;
        d2[i].first=bbb[i].first-bbb[1].first;
        d2[i].second=bbb[i].second-bbb[1].second;        
    }
    if(check(c1,d1)||check(c1,d2)){
        cout<<rey+aa[0].second<<' '<<rex+aa[0].first<<'\n'<<toy+aa[0].second<<' '<<tox+aa[0].first<<'\n';
        return 0;
    }   
    else if(check(c2,d1)||check(c2,d2)){
        cout<<rey+aa[1].second<<' '<<rex+aa[1].first<<'\n'<<toy+aa[1].second<<' '<<tox+aa[1].first<<'\n';
        return 0;
    }
    for(int i=0;i<n2;i++){
        bbb[i].first=-bb[i].second;
        bbb[i].second=bb[i].first;
    }
    sort(bbb.begin(),bbb.end());
    for(int i=0;i<n2;i++){
        d1[i].first=bbb[i].first-bbb[0].first;
        d1[i].second=bbb[i].second-bbb[0].second;
        d2[i].first=bbb[i].first-bbb[1].first;
        d2[i].second=bbb[i].second-bbb[1].second;        
    }
    if(check(c1,d1)||check(c1,d2)){
        cout<<rey+aa[0].second<<' '<<rex+aa[0].first<<'\n'<<toy+aa[0].second<<' '<<tox+aa[0].first<<'\n';
        return 0;
    }   
    else if(check(c2,d1)||check(c2,d2)){
        cout<<rey+aa[1].second<<' '<<rex+aa[1].first<<'\n'<<toy+aa[1].second<<' '<<tox+aa[1].first<<'\n';
        return 0;
    }
}