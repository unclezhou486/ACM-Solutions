#include <bits/stdc++.h>

using namespace std;

const int N=4e3+10;

pair<int,char> a1[N],a2[N],a3[N],a4[N];//x-y+n


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<N;i++){
        a1[i]=a2[i]=a3[i]=a4[i]={0,'a'};
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int op,x;
        char y;
        cin>>op>>x;
        if(op==1){
            cin>>y;
            a1[x]={i,y};
        }
        else if(op==2){
            cin>>y;
            a2[x]={i,y};
        }
        else if(op==3){
            cin>>y;
            a3[x]={i,y};
        }
        else if(op==4){
            cin>>y;
            a4[x+n]={i,y};
        }
        else{
            for(int j=1;j<=n;j++){
                //int res1=x,res2=j,res3=x+j,res4=x-j+n;
                vector<pair<int,char> > vec;
                vec.push_back(a1[x]);
                vec.push_back(a2[j]);
                vec.push_back(a3[x+j]);
                vec.push_back(a4[x-j+n]);
                sort(vec.begin(),vec.end());
                reverse(vec.begin(),vec.end());
                cout<<vec[0].second;
            }
            cout<<'\n';
        }
    }
}