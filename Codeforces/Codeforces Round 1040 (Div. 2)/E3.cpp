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

void print(int x,int cnt){
	for(int i=1;i<=cnt;i++){
		cout<<x<<' ';
	}
}
void print2(int x,int y,int cnt){
	for(int i=1;i<=cnt;i++){
		cout<<x<<' '<<y<<' ';
	}
}

int ci[]={1,1,2,3,5,7,10,15,22,31,44,63,90,127,180};
int ge[]={1,1,3,6,15,28,55,120,253,496,990,2016,4095,8128,16290};



long long queryx(vector<int> &vec,int idr){
	int n=vec.size();
	// cout<<(1<<(n+1))-2+n<<' ';
	int x=1;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(ge[i]==x){
			// print2(vec[i],idr,ci[i]);
			cnt+=2*ci[i];
		}
		else{
			int y=x-ge[i]+1;
			// print(vec[i],y);
			// print(idr,y);
			// print2(vec[i],idr,ci[i-1]);
			cnt+=2*(y+ci[i]-1);
		}
		// print(vec[i],x);
		// print(idr,x);
		// cout<<idr<<' ';
		cnt+=1;
		x<<=1;
	}
	cout<<"? ";
	cout<<cnt<<' ';
	x=1;
	for(int i=0;i<n;i++){
		if(ge[i]==x){
			print2(vec[i],idr,ci[i]);
		}
		else{
			int y=x-ge[i]+1;
			print(vec[i],y);
			print(idr,y);
			print2(vec[i],idr,ci[i]-1);
		}
		// print(vec[i],x);
		// print(idr,x);
		cout<<idr<<' ';
		x<<=1;
	}
	cout<<endl;
	long long res=0;
	cin>>res;
	return res;
}

// ((( )))
//1+2+0+0

//(((()(((
//1+
/*

1 1
1 1
2 3 
3 6 8-6=2
5 15
7 28
10 55
15 120
22 253
31 496
44 990
63 2016
100 5050

*/

//((()))

//1+2+0+0

//() ) (()) )

// ((((xxxx ((xx (x

// x) ) ) xx)) xxxx))))

//

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
		vector<int> vec;
		for(int i=1;i<=n;i++){
			if(i==idl||i==idr) continue;
			vec.push_back(i);
		}
		int m=vec.size();
		for(int i=0;i<m;i++){
			int j=i;
			vector<int> res;
			res.push_back(vec[j]);
			while(j<m-1&&j-i+1<13){
				j++;
				res.push_back(vec[j]);
			}
			int num=j-i+1;
			long long ress=queryx(res,idr);
			for(int k=0;k<num;k++){
				if((ress>>k)&1){
					ans[vec[i+k]]='(';
				}
				else{
					ans[vec[i+k]]=')';
				}
			}
			i=j;
		}
		cout<<"! ";
		for(int i=1;i<=n;i++){
			cout<<ans[i];
		}
		cout<<endl;
	}
}

//((((()))))

//((()((
//1+2+4+8
//((()() 3
//()))() 2

//x) 1

//xx)) 2

//xx))x) 4

//xxx)))x)x) 8

//xxx)))x)x)x)x) 16:


// 
// x+(x)*(x-1)/2<=2^n

//x)x)x) 8

// x)x)

//()()() 6

// ((((xxxx ((xx (x

//


void table(){
	for(int i=1;i<=200;i++){
		cout<<i<<' '<<i+(i)*(i-1)/2<<'\n';
	}
}

int main() {
	// table();
	// return 0;
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}