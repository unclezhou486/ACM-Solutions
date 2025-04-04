#include<bits/stdc++.h>

using namespace std;

constexpr int mod=998244353;

long long qmi(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

long long inv(long long x){
	return qmi(x,mod-2);
}

void solve(){
	long long x=inv(26);
	string str;
	cin>>str;
	int cnt=0;
	int cntl=-1,cntr=-1;
	for(int i=0;i<str.size();i++){
		if(str[i]!='?'&&str[i]!='*'){
			cnt++;
		}
		else if(str[i]=='*'){
			cntl=cnt;
			break;
		}
	}
	cnt=0;
	for(int i=str.size()-1;i>=0;i--){
		if(str[i]!='?'&&str[i]!='*'){
			cnt++;
		}
		else if(str[i]=='*'){
			cntr=cnt;
			break;
		}
	}
	cnt=0;
	if(cntl!=-1&&cntr!=-1){
		cout<<qmi(x,cntl+cntr)<<'\n';
	}
	else cout<<0<<'\n';
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
