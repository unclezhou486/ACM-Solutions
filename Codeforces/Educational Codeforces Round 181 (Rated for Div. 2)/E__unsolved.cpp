#include<bits/stdc++.h>

using namespace std;

/*

1 1 1 1 1 1 1 1 1 1
0 1 2 3 4 5 6 7 8 9
0 0 0 0 1 2 4 6 9 12
0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

*/

/*

1 2 3 4 5 6 7 8 9 10
0 1 3 6 10 15 21 28 36 45
0 0 0 0 1 3 7 13 22 34
0 0 0 0 0 0 0 0 1 3
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

*/

void table(int n,int x){
	vector<vector<set<set<int> > >> vec(n+10,vector<set<set<int> > >(x+10));
	vector<int> a(n+10);
	auto dfs= [&](auto self,int id,int num) -> void{
		if(id>n){
			set<int> se;
			long long sum=0;
			for(int i=1;i<=id-1;i++){
				sum+=a[i];
			}
			long long maxn=0;
			for(int i=1;i<=id-1;i++){
				se.insert(sum-a[i]);
				maxn=max(maxn,sum-a[i]);
			}
			if(*se.begin()!=0&&maxn<=x) vec[se.size()][*se.rbegin()].insert(se);
			if(id==n+9)return;
		}
		for(int i=num;i<=x;i++){
			a[id]=i;
			self(self,id+1,i);
		}
	};
	dfs(dfs,1,1);
	int res=0;
	for(int i=1;i<=x;i++){
		res+=vec[n][i].size();
		cout<<res<<" \n"[i==x];
	}
	// return vec[n].size();
}

void brute(){

	// int n,x;
	// cin>>n>>x;

	// vector<long long> a(n+10);
	// long long ans=0;
	// auto dfs = [&](auto self,int id,int num) -> void{
	// 	if(id==n+1){
	// 		long long res=0;
	// 		long long maxx=0;
	// 		for(int i=1;i<=n;i++){
	// 			res+=a[i];
	// 			maxx=max(a[i],maxx);
	// 		}
    //         if(n==1){
    //             ans++;
    //             return;
    //         }
	// 		if(res%(n-1)==0){
	// 			ans++;
	// 			for(int i=1;i<=n;i++){
	// 				cout<<a[i]<<" \n"[i==n];
	// 			}
	// 		}
	// 		return;
	// 	}
	// 	for(int i=num;i<=x;i++){
	// 		a[id]=i;
	// 		self(self,id+1,i+1);
	// 	}
	// };
	// dfs(dfs,1,1);
	// cout<<ans<<'\n';
}

//1 2 8

//10 9 3

//sum-a[i]

//sum*n-sum

//sum*(n-1)

void solve(){
	for(int i=3;i<=4;i++){
		table(i,16);
	}
	// brute();
	// int x,y;
	// cin>>x>>y;
	// cout<<table(x,y)<<'\n';
	// table(3,10);
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
