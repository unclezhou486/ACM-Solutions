#include <bits/stdc++.h>

using namespace std;

struct node{
	string name;
	int a1,a2,a3,b1,b2,b3,all1,all2,id;
	int val;
};

bool cmp1(node a,node b){
	if(a.all1==b.all1){
		if(a.a1==b.a1){
			return a.name<b.name;
		}
		return a.a1>b.a1;
	}
	return a.all1>b.all1;
}

bool cmp2(node a,node b){
	if(a.all2==b.all2){
		if(a.b1==b.b1){
			return a.name<b.name;
		}
		return a.b1>b.b1;
	}
	return a.all2>b.all2;
}

bool cmp3(node a,node b){
	return a.a1>b.a1;
}

bool cmp4(node a,node b){
	return a.b1>b.b1;
}

bool cmp5(node a,node b){
	if(a.val==b.val){
		if(a.all1+a.all2==b.all1+b.all2){
			if(a.a1+a.b1==b.a1+b.b1){
				return a.name<b.name;
			}
			return a.a1+a.b1>b.a1+b.b1;
		}
		return a.all1+a.all2>b.all1+b.all2;
	}
	return a.val>b.val;
}

void solve(){
	int n;
	cin>>n;
	vector<node> a(n+10),b(n+10);
	int id=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].a1>>a[i].a2>>a[i].a3>>a[i].b1>>a[i].b2>>a[i].b3;
		a[i].id=i;
		if(a[i].name=="crazyzhk") id=i;
	}
	int m,p,q;
	cin>>m>>p>>q;
	int ans=1e9;
	auto check = [&] (int resx,int resy) -> bool {
		vector<int> rnkzhi(n+10);
		vector<int> val(n+10);
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		b[id].a1+=resx,b[id].b1+=resy;
		for(int i=1;i<=n;i++){
			b[i].all1=b[i].a1+b[i].a2+b[i].a3;
			b[i].all2=b[i].b1+b[i].b2+b[i].b3;
		}
		b[0].b1=b[0].a1=-1;
		sort(b.begin()+1,b.begin()+1+n,cmp3);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i].a1!=b[i-1].a1){
				cnt=i;
			}
			rnkzhi[b[i].id]=cnt;
		}
		sort(b.begin()+1,b.begin()+1+n,cmp1);
		int limit1=n*0.25,limit2=n*0.45,limit3=n*0.75;
		int cnt1=n*0.15,cnt2=n*0.25,cnt3=n*0.35;
		for(int i=1;i<=n;i++){
			if(cnt1){
				if(rnkzhi[b[i].id]<=limit1){
					cnt1-=1;
					val[b[i].id]=15;
					continue;
				}
			}
			if(cnt2){
				if(rnkzhi[b[i].id]<=limit2){
					cnt2-=1;
					val[b[i].id]=10;
					continue;
				}
			}
			if(cnt3){
				if(rnkzhi[b[i].id]<=limit3){
					cnt3-=1;
					val[b[i].id]=5;
					continue;
				}
			}
		}
		for(int i=1;i<=n;i++){
			b[i].val+=val[b[i].id];
		}
		for(int i=1;i<=n;i++) val[i]=0;
		//------------------
		sort(b.begin()+1,b.begin()+1+n,cmp4);
		cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i].b1!=b[i-1].b1){
				cnt=i;
			}
			rnkzhi[b[i].id]=cnt;
		}
		sort(b.begin()+1,b.begin()+1+n,cmp2);
		limit1=n*0.25,limit2=n*0.45,limit3=n*0.75;
		cnt1=n*0.15,cnt2=n*0.25,cnt3=n*0.35;
		for(int i=1;i<=n;i++){
			if(cnt1){
				if(rnkzhi[b[i].id]<=limit1){
					cnt1-=1;
					val[b[i].id]=15;
					continue;
				}
			}
			if(cnt2){
				if(rnkzhi[b[i].id]<=limit2){
					cnt2-=1;
					val[b[i].id]=10;
					continue;
				}
			}
			if(cnt3){
				if(rnkzhi[b[i].id]<=limit3){
					cnt3-=1;
					val[b[i].id]=5;
					continue;
				}
			}
		}
		for(int i=1;i<=n;i++){
			b[i].val+=val[b[i].id];
		}
		sort(b.begin()+1,b.begin()+1+n,cmp5);
		bool flag=false;
		for(int i=1;i<=m;i++){
			if(b[i].name=="crazyzhk") flag=true;
		}
		return flag;
	};
	for(int i=0;i<=100-a[id].a1;i++){
		int l=0,r=100-a[id].b1;
		while(l<r){
			int mid=(l+r)>>1;
			int res=p*i+q*mid;
			if(check(i,mid)){
				ans=min(ans,res);
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		if(check(i,l)){
			int res=p*i+q*l;
			ans=min(ans,res);
		}
	}
	if(ans==1e9){
		cout<<"Surely next time\n";
	}
	else{
		cout<<ans<<'\n';
	}
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