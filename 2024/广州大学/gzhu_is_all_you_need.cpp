#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int fl1,fl2,fl3,fl4;
    fl1=fl2=fl3=fl4=0;
    int res=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(res){
            res--;
            continue;
        }
        else{
            ans++;
            if(c=='g') fl1++;
            else if(c=='z') fl2++;
            else if(c=='h') fl3++;
            else if(c=='u') fl4++;
            if(fl1&&fl2&&fl3&&fl4) res+=fl1+fl2+fl3+fl4,fl1=fl2=fl3=fl4=0;
        }
    }
    cout<<ans<<'\n';
}
