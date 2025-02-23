#include <bits/stdc++.h>

using namespace std;

void solve(){
	int k;
	string s;
	cin>>k;
	cin>>s;
	int n=s.size();
	if(k==2){
		int anss=0;
		int ansss=0;
		for(int i=0;i<n;i++){
			if(i%2){
				if(s[i]=='1') anss+=1;
				else ansss+=1;
			}
			else{
				if(s[i]=='0') anss+=1;
				else ansss+=1;
			}
		}
		cout<<min(anss,ansss)<<' ';
		if(anss>ansss){
			for(int i=0;i<n;i++){
				cout<<i%2;
			}
		}
		else{
			for(int i=0;i<n;i++){
				cout<<1-(i%2);
			}
		}
		return;
	}
	int cnt=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(i>0&&s[i]==s[i-1]){
			cnt+=1;
		}
		else{
			cnt=1;
		}
		if(cnt==k){
			if(i<n-1){
				if(s[i]==s[i+1]){
					s[i]='1'-s[i]+'0';
					cnt=1;
					ans+=1;
				}
				else{
					s[i-1]='1'-s[i]+'0';
					cnt=1;
					ans+=1;
				}
			}
			else{
				s[i]='1'-s[i]+'0';
				ans+=1;
			}
		}
	}
	cout<<ans<<' '<<s<<'\n';
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