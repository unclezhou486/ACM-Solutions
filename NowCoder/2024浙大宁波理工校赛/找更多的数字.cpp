#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e6+10;

int n, m, maxn;
int c[N];
int cnt[N];
long long ans1[N], ans2[N];
set<int> ans;
vector<int> anss[N];
struct query {
  int l, r, id;
  bool operator<(const query &x) const {
    if (l / maxn != x.l / maxn) return l < x.l;
    return (l / maxn) & 1 ? r < x.r : r > x.r;
  }
}qu[N];

void add(int i) {
  cnt[i]++;
  if(cnt[i]==1){
    ans.insert(i);
  }
  if(cnt[i]==2){
    ans.erase(i);
  }
}

void del(int i) {
  if(cnt[i]==2){
    ans.erase(i);
  }
  cnt[i]--;
  if(cnt[i]==1){
    ans.insert(i);
  }
  if(cnt[i]==0){
    ans.erase(i);
  }
}

void solve(){
  cin >> n >> m;
  maxn = sqrt(n);
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 0; i < m; i++) cin >> qu[i].l >> qu[i].r, qu[i].id = i;
  sort(qu, qu + m);
  for (int i = 0, l = 1, r = 0; i < m; i++) {  // 具体实现
    while (l > qu[i].l) add(c[--l]);
    while (r < qu[i].r) add(c[++r]);
    while (l < qu[i].l) del(c[l++]);
    while (r > qu[i].r) del(c[r--]);
    vector<int> vecc;
    for(auto x:ans){
      vecc.push_back(x);
    }
    anss[qu[i].id]=vecc;
  }
  for(int i=0;i<m;i++){
    for(auto x:anss[i]){
      cout<<x<<' ';
    }
    cout<<'\n';
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
  
}