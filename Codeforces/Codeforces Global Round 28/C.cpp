#include <bits/stdc++.h>

using namespace std;

void solve(){
	string str;
	cin>>str;
	int n=str.size();
	vector<int> a(n+10);
	for(int i=0;i<n;i++){
		a[i+1]=str[i]-'0';
	}
	bool flag=false;
	int ansl=n,ansr=n;
	for(int i=1;i<=n;i++){
		if(flag) break;
		if(a[i]==0){
			string ans="";
			for(int j=i;j<=n;j++){
				ans+='0';
			}
			for(int l=1;l+(n-i)<=n;l++){
				if(a[l]==1){
					int r=l+(n-i);
					string res="";
					for(int k=l;k<=r;k++){
						int x=a[i+(k-l)]^a[k];
						char ch=x+'0';
						res=res+ch;
					}
					if(res>ans){
						ans=res;
						ansl=l,ansr=r;
					}
					flag=true;
				}
			}
		}
	}
	cout<<ansl<<' '<<ansr<<' '<<1<<' '<<n<<'\n';
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