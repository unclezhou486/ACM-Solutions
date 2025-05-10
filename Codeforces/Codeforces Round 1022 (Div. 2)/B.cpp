#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,x;
	cin>>n>>x;
	int xx=x;
	int cnt=0;
	int min0=-1,min1=2e9;
	vector<pair<int,int> > vec;
	for(int i=0;i<=30;i++){
		if((x>>i)&1){
			cnt++;
			if(min1==-1){
				min1=(1<<i);
			}
			vec.push_back({1<<i,n-1});
		}
		else{
			if(min0==-1){
				min0=(1<<i);
			}
			vec.push_back({1<<i,n});
		}
	}
	int res=n-cnt;
	long long ans=x;
	// while(res){
		for(auto [val,count]:vec){
			if(res<=0) break;
			int ress=count/2*2;
			if(ress>res){
				if(res%2){
					ans+=1ll*(res+1)*val;
				}
				else{
					ans+=1ll*res*val;
				}
				res=0;
				break;
			}
			res-=ress;
			ans+=1ll*ress*val;
		}
	// }
	if(res>0){
		cout<<-1<<'\n';
	}
	else{
		cout<<ans<<'\n';
	}
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

//   11
//   1
//    1