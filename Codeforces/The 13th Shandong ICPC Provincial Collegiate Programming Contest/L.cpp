#include <bits/stdc++.h>

using namespace std;

struct node{
	int a,b,c,d;
};

vector<node> vec;

// void print(int a,int b,int c,int d){
// 	cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
// }

// int a[1000][1000];



void ins(int a,int b,int c,int d){
	vec.push_back((node){a,b,c,d});
}
void solve(){
	int n,bi,bj;
	cin>>n>>bi>>bj;
	int aa=n,bb=1,xx=1,yy=n;
	bool flag=true;
	if(n==1){
		cout<<"Yes\n0\n";
		return;
	}
	while(flag){
		flag=false;
		if(bi==xx){
			int x=aa;
			for(int i=bi;i<bj;i+=1){
				ins(x,i,bi-x,aa-i);
				x-=1;
			}
			for(int i=aa;i>bj;i-=1){
				ins(x,i,bi-x,bj-i);
				x-=1;
			}
		}
		else if(bi==aa){
			int x=xx;
			for(int i=bb;i<bj;i+=1){
				ins(x,i,aa-x,yy-i);
				x+=1;
			}
			for(int i=yy;i>bj;i-=1){
				ins(x,i,aa-x,bj-i);
				x+=1;
			}
		}
		else if(bj==bb){
			int x=yy;
			for(int i=bj;i<bi;i+=1){
				ins(i,x,aa-i,bb-x);
				x-=1;
			}
			for(int i=aa;i>bi;i-=1){
				ins(i,x,bi-i,bb-x);
				x-=1;
			}
		}
		else if(bj==yy){
			int x=bb;
			for(int i=aa;i>bi;i--){
				ins(i,x,xx-i,yy-x);
				x+=1;
			}
			for(int i=xx;i<bi;i++){
				ins(i,x,bi-i,yy-x);
				x+=1;
			}
		}
		else{
			flag=true;
			ins(aa,bb,xx-aa,yy-bb);
			aa--,bb++;
			ins(xx,yy,aa-xx,bb-yy);
			xx++,yy--;
		}
	}
	cout<<"Yes\n";
	cout<<vec.size()<<'\n';
	for(auto x:vec){
		cout<<x.a<<' '<<x.b<<' '<<x.c<<' '<<x.d<<'\n';
		// int a1=x.a,a2=x.a+x.c;
		// int b1=x.b,b2=x.b+x.d;
		// if(a1>a2) swap(a1,a2);
		// if(b1>b2) swap(b1,b2);
		// for(int i=a1;i<=a2;i++){
		// 	a[i][x.b]=1;
		// }
		// for(int i=b1;i<=b2;i++){
		// 	a[x.a][i]=1;
		// }
	}
	// bool fl=true;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		if(a[i][j]) cout<<"*";
	// 		else cout<<" ";
	// 		if(a[i][j]>1) fl=false;
	// 	}
	// 	cout<<'\n';
	// }
	// if(!fl){
	// 	cout<<"Wrong\n";
	// }
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