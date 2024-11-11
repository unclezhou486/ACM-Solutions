#include <bits/stdc++.h>
using namespace std;

struct team {
    string name;
    int solved;
    int penalty;
    bool operator<(const team& rhs) {
        return solved == rhs.solved? penalty < rhs.penalty : solved > rhs.solved;
    }
};

void solve(){
    int ans = 0;
    int n; cin >> n;
    vector<team> a(n);
    vector<string> a_names(n);
    for (int i = 0; i < n; ++i) {
        cin  >> a[i].name >> a[i].solved >> a[i].penalty;
        a_names[i] = a[i].name;
    }
    sort(a.begin(), a.end());
    sort(a_names.begin(), a_names.end());

    int m; cin >> m;
    vector<team> b(m);
    vector<string> b_names(m);
    for (int i = 0; i < m; ++i) {
        cin  >> b[i].name >> b[i].solved >> b[i].penalty;
        b_names[i] = b[i].name;
    }
    sort(b.begin(), b.end());
    sort(b_names.begin(), b_names.end());
    for (int i = 0, j = 1; i < n; ++i) {
        if (!binary_search(b_names.begin(), b_names.end(), a[i].name)) j++;
        if (a[i].name == "lzr010506") {
            ans = j;
            break;
        }
    }
    for (int i = 0, j = 1; i < m; ++i) {
        if (!binary_search(a_names.begin(), a_names.end(), b[i].name)) j++;
        if (b[i].name == "lzr010506") {
            ans = min(j, ans);
            break;
        }
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
/*
5
0 1
0 2
1 3
0 6
2 100000
*/