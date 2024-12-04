#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

const int N=2e5+10;

int n;
int a[N];

int l[N];

long long ans;

void solve(){
	ans=0;
	cin>>n;
	map<int,int> ma;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=ma[a[i]];
		ma[a[i]]=i;
		ans+=1ll*(i-l[i])*(n-i+1);
	}
	cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}