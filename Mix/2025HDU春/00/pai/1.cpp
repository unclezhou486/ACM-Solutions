#include <bits/stdc++.h>
using namespace std;



void solve(){
	int n;
	cin>>n;
	vector<char> a(n+10),b(n+10);
	vector<stack<int> > id(300);
	stack<int> lock;
	stack<char> st;
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	auto check = [&] (char ch,int &ans) -> void{
		int siz=st.size();
		if('0'<=ch&&ch<='9'){
			if(id[ch].empty()){
				id[ch].push(siz+1);
				st.push(ch);
			}
			else{
				int idd=id[ch].top();
				if(lock.size()){
					if(lock.top()>idd){
						id[ch].push(siz+1);
						st.push(ch);
						lock.pop();
					}
					else{
						int cnt=1;
						while(st.size()&&st.size()!=idd){
							id[st.top()].pop();
							st.pop();
							cnt+=1;
						}
						id[st.top()].pop();
						st.pop();
						cnt+=1;
						ans+=cnt;
						return;
					}
				}
				else{
					int cnt=1;
					while(st.size()&&st.size()!=idd){
						id[st.top()].pop();
						st.pop();
						cnt+=1;
					}
					id[st.top()].pop();
					st.pop();
					cnt+=1;
					ans+=cnt;
					return;
				}
			}
		}
		else if(ch=='Q'){
			id[ch].push(siz+1);
			lock.push(siz+1);
			// locking^=1;
			st.push(ch);
		}
		else if(ch=='J'){
			if(lock.empty()){
				int cnt=1;
				while(st.size()){
					id[st.top()].pop();
					st.pop();
					cnt+=1;
				}
				ans+=cnt;
			}
			else{
				int cnt=1;
				while(st.size()!=lock.top()){
					id[st.top()].pop();
					st.pop();
					cnt+=1;
				}
				id[st.top()].pop();
				lock.pop();
				st.pop();
				cnt+=1;
				ans+=cnt;
			}
		}
		else{
			id[ch].push(siz+1);
			st.push(ch);
			if(lock.size()){
				lock.pop();
			}
		}
	};
	for(int i=1;i<=n;i++){
		check(a[i],ans1);
		check(b[i],ans2);
	}
	cout<<ans1<<' '<<ans2<<'\n';
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}