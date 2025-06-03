#include <bits/stdc++.h>

using namespace std;

char change(char ch){
	if(ch=='0') return '1';
	else return '0';
}

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vector<int> ans;
	int head=0,tail=n-1;
	int op=0;
	for(int i=n-1;i>=0;i--){
		char chh=a[tail];
		if(op) chh=change(chh);
		if(chh==b[i]) {
			// tail--;
			if(head<tail){
				tail--;
			}
			else{
				tail++;
			}
			continue;
		}
		char ch=a[head];
		if(op) ch=change(ch);
		int len=abs(tail-head)+1;
		if(head<tail) head++;
		else head--;
		if(ch==b[i]){
			ans.push_back(1);
			ans.push_back(len);
			op^=1;
			swap(head,tail);
		}
		else{
			ans.push_back(len);
			if(len-1)ans.push_back(len-1);
			// if(head<tail)
		}
	}
	cout<<ans.size()<<' ';
	for(auto x:ans){
		cout<<x<<' ';
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
//a4!=b4

//2steps

//a1 a2 a3 a4

//a4^1 a3^1 a2^1 a1^1

//a2 a3 a4 a1^1

//2steps

//a1 a2 a3 a4

//a1^1 a2 a3 a4

//a4^1 a3^1 a2^1 a1
