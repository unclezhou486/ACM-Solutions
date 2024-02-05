#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int a[N];
int l[N];
int la[N];

void solve(){
	priority_queue<int,vector<int>,greater<int> > q;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],la[a[i]]=0,l[i]=0;
	
	for(int i=n;i>=1;i--) {
		if(!la[a[i]]){
			q.push(i);
		}
		else{
			l[la[a[i]]]=i;
		}
		la[a[i]]=i;
	}
	int ans=0;
	while(q.size()){
		ans++;
		int x=q.top();
//		cout<<"f"<<' '<<x<<'\n';
		if(x==1) break;
		q.pop();
		vector<int> y;
		while(q.size()){
			if(q.top()>x){
				int z=q.top();
//				cout<<"u"<<' '<<z<<'\n';
				q.pop();
				while(z>x) z=l[z];
				y.push_back(z);
			}
			else{
				break;
			}
		}
		for(int i=0;i<y.size();i++){
			if(y[i])q.push(y[i]);
		}
		if(l[x])q.push(l[x]);
	}
	cout<<ans<<'\n';
}

/*
1
3
1 2 1
*/

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 