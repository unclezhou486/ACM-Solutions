#include <bits/stdc++.h>
#define int long long
using namespace std;

int ask(int l,int r){
	cout<<"xor "<<l<<' '<<r<<endl;
	int x;
	cin>>x;
	return x;
}

void answer(int a,int b,int c){
	cout<<"ans"<<' '<<a<<' '<<b<<' '<<c<<endl;
}

void solve(){
	int n;
	cin>>n;
	int res=ask(1,n);
	if(res){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(ask(l,mid)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		int a=l;
		l=1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			int ress=ask(l,mid);
			if(l<=a&&a<=mid) ress^=a;
			if(ress) r=mid;
			else l=mid+1;
		}
		int b=l;
		int c=res^a^b;
		answer(a,b,c);
	}
	else{
		// long long L=1,R;
		long long x;
		for(int i=60;~i;i--){
			long long r=min((1ll<<i)-1,n);
			long long l=min((1ll<<(i-1)),n);
			if(l==r) continue;
			if(ask(l,r)){
				x=(1ll<<(i-1))-1;
				break;
			}
		}
		long long l=1,r=x;
		while(l<r){
			int mid=(l+r)>>1;
			if(ask(l,mid)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		long long a=l;
		l=x+1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			int ress=ask(l,mid);
			if(l<=a&&a<=mid) ress^=a;
			if(ress) r=mid;
			else l=mid+1;
		}
		long long b=l;
		long long c=res^a^b;
		answer(a,b,c);
	}
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