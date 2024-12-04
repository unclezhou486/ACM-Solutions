#include <bits/stdc++.h>

using namespace std;

void solve(int l = 0, int r = 0) {
    int L = l, R = r;
//    swap(L, R);
    cin >> L >> R;
    int Llen = 0, Rlen = 0;
    while ((1 << Llen + 1) <= L) Llen++;
    while ((1 << Rlen + 1) <= R) Rlen++;
    const int S = 100, T = 0;
    vector<pair<int, int>> e[101];
    int p = 0;
    if (Llen + 2 <= Rlen) p = Rlen - 1;
    else {
        for (int i = 0; i < Llen; ++i) {
            if ((L >> i & 1) == 0 && R >> i > (L >> i ^ 1)) p = max(p, i);
        }
        for (int i = 0; i < Rlen; ++i) {
            if ((R >> i & 1) == 1 && (R >> i ^ 1) << i >= L) p = max(p, i);
        }
    }
    for (int i = 1; i <= p; ++i) {
        e[i].emplace_back(i - 1, 0);
        e[i].emplace_back(i - 1, 1);
    }
    for (int i = Llen + 1; i <= Rlen - 1; ++i) {
        e[S].emplace_back(i, 1);
    }
    if (Rlen) {
        e[p + 1].emplace_back(0, R & 1);
        for (int i = 0; i < Rlen; ++i) {
            if (i) e[p + 1].emplace_back(p, R >> i & 1);
            if ((R >> i & 1) == 1 && (R >> i ^ 1) << i >= L) e[p + 1].emplace_back(i, 0);
            p++;
        }
        e[S].emplace_back(p, 1);
    }
    if (Llen) {
        e[p + 1].emplace_back(0, L & 1);
        for (int i = 0; i < Llen; ++i) {
            if (i) e[p + 1].emplace_back(p, L >> i & 1);
            if ((L >> i & 1) == 0 && R >> i > (L >> i ^ 1)) e[p + 1].emplace_back(i, 1);
            p++;
        }
        e[S].emplace_back(p, 1);
    } else e[S].emplace_back(0, 1);
    e[++p] = e[S];
    p++;
    cout << p << '\n';
//    bool check[600] = {};
//
//    auto dfs = [&](auto& dfs, int cur, int x) -> void {
//     if (e[cur].empty()) check[x] = true;
//     else {
//         for (auto& [to, w]: e[cur]) {
//             dfs(dfs, to, x * 2 + w);
//         }
//     }
//    };
//    dfs(dfs, p - 1, 0);
//    for (int i = L; i <= R; ++i) {
//        if (!check[i]) {
//            cout << L << ' ' << R << ' ' << i << endl;
//            return;
//        }
//    }
//
//    for (int i = 0; i < L; ++i) {
//        if (check[i]) {
//            cout << L << ' ' << R << ' ' << i << endl;
//            return;
//        }
//    }
//
//    for (int i = R + 1; i < 599; ++i) {
//        if (check[i]) {
//            cout << L << ' ' << R << ' ' << i << endl;
//            return;
//        }
//    }
//    for (int i = 1; i < p; ++i) {
//        if (e[i].size() == 0) cout << L << ' ' << R << ' ' << i << endl;
//    }
//    int in[5000] = {};
//
//    for (int i = 0; i < p; ++i) {
//        for (auto& [to, w]: e[i])
//            in[to]++;
//    }
//
//    for (int i = 0; i < p - 1; ++i) {
//        if (in[i] == 0) cout << L << ' ' << R << ' ' << i << endl;
//    }

    for (int i = 0; i < p; ++i) {
        std::sort(e[i].begin(), e[i].end());
        e[i].resize(std::unique(e[i].begin(), e[i].end()) - e[i].begin());
        cout << e[i].size();
        for (const auto &[u, w]: e[i]) {
            cout << ' ' << u + 1 << ' ' << w;
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
////solve(1,1000000);
//    for (int l = 1; l < 500; ++l)
//        for (int r = l; r < 500; ++r)
//            solve(l, r);
    return 0;
}