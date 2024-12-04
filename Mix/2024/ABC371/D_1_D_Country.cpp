#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

const int N=2e5+10;

int n,q;

struct node{
	int x,p;
}a[N];

long long pre[N<<2];
int l[N],r[N];

void solve(){
	map<int,int> ma;
	set<int> se;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		se.insert(a[i].x);
		// ma[a[i].x]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].p;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l[i]>>r[i];
		se.insert(l[i]-1);
		se.insert(r[i]);
	}
	int cnt=0;
	for(auto x:se){
		ma[x]=++cnt;
	}
	for(int i=1;i<=n;i++){
		pre[ma[a[i].x]]+=a[i].p;
	}
	for(int i=1;i<=cnt;i++){
		pre[i]=pre[i-1]+pre[i];
	}
	for(int i=1;i<=q;i++){
		int x=ma[l[i]-1],y=ma[r[i]];
		cout<<pre[y]-pre[x]<<'\n';
	}
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