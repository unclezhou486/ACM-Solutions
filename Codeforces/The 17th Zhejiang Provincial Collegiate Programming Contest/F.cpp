#include <bits/stdc++.h>

using namespace std;

/*
(w1 x + b1)(w2x+b2)<0

w1w2 x*x + (w1b2+b1w2)x + b1b2<0

x=((w1b1+b1w2)/(-2*w1*w2))

*/

void solve(){
	int n;
	cin>>n;
	vector<int> w1(n+10),w2(n+10);
	int b1,b2;
	for(int i=1;i<=n;i++){
		cin>>w1[i];
	}
	cin>>b1;
	for(int i=1;i<=n;i++){
		cin>>w2[i];
	}
	cin>>b2;
	if(b1*b2<0){
		for(int j=1;j<=n;j++){
			cout<<0<<" \n"[j==n];
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(w1[i]*w2[i]==0){
			if(w1[i]||w2[i]){
				for(int j=1;j<=n;j++){
					
				}
			}
		}
		else if(w1[i]*w2[i]>0){
			if(1.0*b1/w1[i]!=1.0*b2/w2[i]){
				double res=1.0*(w1[i]*b2+w2[i]*b1)/(-2*w1[i]*w2[i]);
				if(res>10000) res=10000;
				if(res<-10000) res=-10000;
				for(int j=1;j<=n;j++){
					cout<<(j==i?res:0)<<" \n"[j==n];
				}
				return;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				cout<<(j==i?10000:0)<<" \n"[j==n];
			}
			return;
		}
		int bb1=b1+1*w1[i];
		int bb2=b2+1*w2[i];
		for(int j=0;j<i;j++){
			if(1.0*bb1/w1[j]!=1.0*bb2/w2[j]){
				double res=1.0*(w1[j]*bb2+w2[j]*bb1)/(-2*w1[j]*w2[j]);
				if(res>10000) res=10000;
				if(res<-10000) res=-10000;
				for(int k=1;k<=n;k++){
					if(k==i){
						cout<<1<<" \n"[k==n];
					}
					else if(k==j){
						cout<<res<<" \n"[k==n];
					}
					else{
						cout<<0<<" \n"[k==n];
					}
				}
				return;
			}		
		}
	}
	cout<<"No\n";
	return;
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