#include <bits/stdc++.h>

using namespace std;

void solve(){
	int q;
	cin>>q;
	deque<int> a,b;
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int x;
			cin>>x;
			a.push_front(x);
			if(a.size()>b.size()){
				b.push_front(a.back());
				a.pop_back();
			}
		}
		else if(op==2){
			int x;
			cin>>x;
			b.push_back(x);
			if(a.size()+1<b.size()){
				a.push_back(b.front());
				b.pop_front();
			}
		}
		else{
			if(a.size()==b.size()){
				cout<<a.back()<<'\n';
				a.pop_back();
				if(a.size()+1<b.size()){
					a.push_back(b.front());
					b.pop_front();
				}
			}
			else{
				cout<<b.front()<<'\n';
				b.pop_front();
				if(a.size()<b.size()){
					a.push_back(b.front());
					b.pop_front();
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

//  3 1 2 4