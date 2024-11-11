#include <bits/stdc++.h>

using namespace std;

int cal(int x){
    int res=0;
    if(!x) res=1;
    while(x){
        res++;
        x/=10;
    }
    return res;
}

void solve(){
    int n,y;
    set<int> ans;
    cin>>n;
    char s[10];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    cin>>y;
    for(int a=0;a<=9;a++){
        for(int b=0;b<=9;b++){
            for(int c=0;c<=9;c++){
                for(int d=0;d<=9;d++){
                    set<int> res={a,b,c,d};
                    if(res.size()<4) continue;
                   
                    for(int _=0;_<=9;_++){
                        int x=0;
                        for(int i=1;i<=n;i++){
                            if(s[i]=='a'){
                                x=x*10+a;
                            }
                            else if(s[i]=='b'){
                                x=x*10+b;
                            }
                            else if(s[i]=='c'){
                                x=x*10+c;
                            }
                            else if(s[i]=='d'){
                                x=x*10+d;
                            }
                            else if(s[i]=='_'){
                                x=x*10+_;
                            }
                            else{
                                int r=s[i]-'0';
                                x=x*10+r;
                            }
                        }
                        if(((x%8)==0)&&x<=y&&(cal(x)==n)){
                            ans.insert(x);
                        }
                    }
                }
            }
        }
    }
    cout<<ans.size()<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}