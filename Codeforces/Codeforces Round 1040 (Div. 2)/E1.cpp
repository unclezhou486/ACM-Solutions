#include <bits/stdc++.h>

using namespace std;

long long queryall(int l,int r){
	cout<<"? ";
	cout<<(r-l+1)<<' ';
	for(int i=l;i<=r;i++){
		cout<<i<<' ';
	}
	cout<<endl;
	long long res;
	cin>>res;
	return res;
}

long long query2(int x,int y){
	cout<<"? "<<2<<' '<<x<<' '<<y<<endl;
	long long res;
	cin>>res;
	return res;
}

long long query6(int a,int b,int c,int d,int e,int f){
	cout<<"? "<<6<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<f<<endl;
	long long res;
	cin>>res;
	return res;
}

void solve() {
	int n;
	cin>>n;
	long long x=queryall(1,n);
	if(x==0){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(query2(n,mid)==1) l=mid;
			else r=mid-1;
		}
		cout<<"! ";
		for(int i=1;i<=l;i++){
			cout<<')';
		}
		for(int i=l+1;i<=n;i++){
			cout<<'(';
		}
		cout<<endl;
	}
	else{
		vector<char> ans(n+1);
		int l=1,r=n;
		int idl=-1,idr=-1;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(queryall(l,mid)){
				r=mid;
			}
			else if(queryall(mid+1,r)){
				l=mid+1;
			}
			else{
				idl=mid,idr=mid+1;
				break;
			}
		}
		if(idl==-1){
			idl=l,idr=r;
		}
		ans[idl]='(',ans[idr]=')';
		queue<int> q;
		for(int i=1;i<=n;i++){
			if(i==idl||i==idr) continue;
			q.push(i);
		}
		while(!q.empty()){
			if(q.size()>1){
				int x=q.front();
				q.pop();
				int y=q.front();
				q.pop();
				long long res=query6(idl,x,y,idr,idl,idr);
				if(res==3){
					ans[x]='(',ans[y]='(';
				}
				else if(res==2){
					ans[x]=')',ans[y]=')';
				}
				else if(res==4){
					ans[x]='(',ans[y]=')';
				}
				else{
					ans[x]=')',ans[y]='(';
				}
			}
			else{
				int x=q.front();
				q.pop();
				if(query2(idl,x)==1){
					ans[x]=')';
				}
				else{
					ans[x]='(';
				}
			}
		}
		cout<<"! ";
		for(int i=1;i<=n;i++){
			cout<<ans[i];
		}
		cout<<endl;
	}
}

//((()() 3
//()))() 2
//(())() 4
//()()() 6

//

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}