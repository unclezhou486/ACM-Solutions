#include <bits/stdc++.h>

using namespace std;

struct node{
	int l,r;
	int id;
	bool operator<(const node &a) const{
		if(l==a.l) return r>a.r;
		return l<a.l;
	}
};

void solve() {
	int n;
	cin>>n;
	vector<int> vis(2*n+1);
	vector<node > a(n+1); 
	vector<int> ans;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		a[i].id=i;
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=a[i].l;j<=a[i].r;j++){
			if(!vis[j]){
				flag=false;
				vis[j]=1;
			}
		}
		if(!flag){
			ans.push_back(a[i].id);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}