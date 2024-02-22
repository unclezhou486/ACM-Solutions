#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n,a[N];
int dp[N];

void fixmin(set<int>& se){
    while(se.size()>1){
        se.erase(--se.end());
    }
}

void fixmax(set<int>& se){
    while(se.size()>1){
        se.erase(se.begin());
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        set<int> mx1,mn1,mx2,mn2,mx3,mn3,mx4,mn4,mx5,mn5;
        for(int j=i;j<=n;j++){
            for(auto& k:mx5){
                dp[j]=max(dp[i-1]+k-a[j],dp[j]);
            }
            for(auto& k:mn5){
                dp[j]=max(dp[i-1]+k-a[j],dp[j]);
            }
            for(auto& k:mn4){
                mn5.insert(k*a[j]);
                mx5.insert(k*a[j]);
            }
            for(auto& k:mx4){
                mn5.insert(k*a[j]);
                mx5.insert(k*a[j]);
            }
            for(auto& k:mn3){
                mn4.insert(k-a[j]);
                mx4.insert(k-a[j]);
            }
            for(auto& k:mx3){
                mn4.insert(k-a[j]);
                mx4.insert(k-a[j]);
            }
            for(auto& k:mn2){
                mn3.insert(k*a[j]);
                mx3.insert(k*a[j]);
            }
            for(auto& k:mx2){
                mn3.insert(k*a[j]);
                mx3.insert(k*a[j]);
            }
            for(auto& k:mn1){
                mn2.insert(k-a[j]);
                mx2.insert(k-a[j]);
            }
            for(auto& k:mx1){
                mn2.insert(k-a[j]);
                mx2.insert(k-a[j]);
            }
            mn1.insert(a[j]);
            mx1.insert(a[j]);
            fixmin(mn1);fixmin(mn2);fixmin(mn3);fixmin(mn4);fixmin(mn5);
            fixmax(mx1);fixmax(mx2);fixmax(mx3);fixmax(mx4);fixmax(mx5);
        }
    }
    cout<<*max_element(dp+1,dp+1+n)<<'\n';
}