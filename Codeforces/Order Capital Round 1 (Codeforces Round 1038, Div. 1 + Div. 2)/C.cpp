#include<bits/stdc++.h>

using namespace std;

struct node{
	int x,y,id;
};

bool cmp1(node a,node b){
	return a.x<b.x;
}

bool cmp2(node a,node b){
	return a.y<b.y;
}

void solve(){
	int n;
	cin>>n;
	vector<int> x(n),y(n);
	vector<node> a(n);
	vector<int> vis(n);
	// set<pair<int,int> > se1,se2;
	// vector<pair<int,int> > vec1,vec2;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		x[i]=a[i].x,y[i]=a[i].y;
		a[i].id=i;
		// se1.insert({a[i].x+a[i].y,i});
		// se2.insert({a[i].x-a[i].y,i});
		// vec1.push_back({a[i].x+a[i].y,i});
		// vec2.push_back({a[i].x-a[i].y,i});
	}
	vector<int> vis1(n),vis2(n);
	sort(a.begin(),a.end(),cmp1);
	for(int i=0;i<n/2;i++){
		vis1[a[i].id]=-1;
	}
	for(int i=n/2;i<n;i++){
		vis1[a[i].id]=1;
	}
	sort(a.begin(),a.end(),cmp2);
	for(int i=0;i<n/2;i++){
		vis2[a[i].id]=-1;
	}
	for(int i=n/2;i<n;i++){
		vis2[a[i].id]=1;
	}
	vector<pair<int,int> > ans;
	vector<int> A,B,C,D;
	for(int i=0;i<n;i++){
		if(vis1[i]==-1&&vis2[i]==-1) A.push_back(i);
		else if(vis1[i]==1&&vis2[i]==-1) B.push_back(i);
		else if(vis1[i]==-1&&vis2[i]==1) C.push_back(i);
		else D.push_back(i);
	}
	for(int i=0;i<A.size();i++){
		ans.push_back({A[i]+1,D[i]+1});
	}
	for(int i=0;i<B.size();i++){
		ans.push_back({B[i]+1,C[i]+1});
	}
	// int resans=0;
	// for(int i=1;i<=n/2;i++){
	// 	// auto [res1,id1]=*se1.begin();
	// 	// auto [res2,id2]=*se1.rbegin();
	// 	// auto [res3,id3]=*se2.begin();
	// 	// auto [res4,id4]=*se2.rbegin();
	// 	// // int idd1,idd2;
	// 	// cout<<res2-res1<<' '<<res4-res3<<'\n';
	// 	// cout<<id1<<' '<<id2<<' '<<id3<<' '<<id4<<'\n';
	// 	// if(res2-res1<res4-res3){
	// 	// 	swap(id1,id3);
	// 	// 	swap(id2,id4);
	// 	// 	swap(res1,res3);
	// 	// 	swap(res2,res4);
	// 	// }
	// 	// resans+=res2-res1;
	// 	// ans.push_back({id1+1,id2+1});
	// 	// se1.erase({a[id1].x+a[id1].y,id1});
	// 	// se1.erase({a[id2].x+a[id2].y,id2});
	// 	// se2.erase({a[id1].x-a[id1].y,id1});
	// 	// se2.erase({a[id2].x-a[id2].y,id2});
	// }
	// cout<<resans<<'\n';
	// sort(vec1.begin(),vec1.end());
	// sort(vec2.begin(),vec2.end());
	// set<>
	// sort(a.begin(),a.end());
	// int id1=0,id2=0;
	// auto dis = [&] (int a,int b) -> int {
	// 	return abs(x[a]-x[b])+abs(y[a]-y[b]);
	// };
	// for(int i=0;i<n;i++){
	// 	if(vis[a[i].id]) continue;
	// 	while(vis[vec1[id1].second]||vec1[id1].second==a[i].id) id1++;
	// 	while(vis[vec2[id2].second]||vec2[id2].second==a[i].id) id2++;
	// 	// cout<<a[i].id<<' '<<vec1[id1].second<<' '<<vec2[id2].second<<'\n';
	// 	int i1=vec1[id1].second,i2=vec2[id2].second;
	// 	if(dis(a[i].id,i1)<dis(a[i].id,i2)){
	// 		swap(i1,i2);
	// 	}
	// 	ans.push_back({a[i].id+1,i1+1});
	// 	vis[a[i].id]=1;
	// 	vis[i1]=1;
	// }
	for(auto [x,y]:ans){
		cout<<x<<' '<<y<<'\n';
	}
}
// x_i-x_j+|y_i-y_j|

//y_i-y_j

// x_i+y_i-(x_j+y_j)  (y_j < y_i) || x_i-y_i-(x_j-y_j)  (y_j > y_i) 
// ( < y_i) min(x_j+y_j)

// ( > y_i) min(x_j-y_j)

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
