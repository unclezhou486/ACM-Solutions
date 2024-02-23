#include <bits/stdc++.h>

using namespace std;

double p;

int main(){
    cin>>p;
    cout<<fixed<<setprecision(7)<<(1-p)*(1-p)*p*p*p+p*p*(1-p)*(1-p)*(1-p)<<'\n';
}