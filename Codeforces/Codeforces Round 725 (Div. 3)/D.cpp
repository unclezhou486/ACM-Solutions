#include <bits/stdc++.h>

using namespace std;

constexpr int N=1e5+10;

int b[N];
vector<int> pri;
void table(){
	for(int i=2;i<N;i++){
		if(b[i]) continue;
		pri.push_back(i);
		for(int j=i*2;j<N;j+=i){
			b[j]=1;
		}
	}
}

void solve(){
	int a,b,k;
	cin>>a>>b>>k;
	if(k==1){
		if(a!=b&&(a%b==0||b%a==0)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	else{
		int cnta=0,cntb=0;
		auto check = [&](int x) -> int {
			int res=0;
			// for(int i=2;i<=x/i;i++){
			// 	while(x%i==0){
			// 		x/=i;
			// 		res++;
			// 	}
			// }
			for(auto y:pri){
				if(y>x) break;
				while(x%y==0){
					x/=y;
					res++;
				}
			}
			if(x!=1){
				res++;
			}
			return res;
		};
		cnta=check(a),cntb=check(b);

		if(k<=cnta+cntb){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}

int main(){
	table();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}