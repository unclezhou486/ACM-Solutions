#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using ll = long long;

// 使用 mt19937_64 生成高质量的 64 位随机数
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// 生成 [l, r] 范围内的随机整数
ll randint(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

// 生成一棵 n 个节点的随机树
void generate_tree(int n, vector<pair<int, int>>& edges) {
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    shuffle(p.begin() + 1, p.end(), rng); // 随机节点编号，避免生成链状树

    for (int i = 2; i <= n; ++i) {
        int u = p[i];
        int v = p[randint(1, i - 1)];
        edges.push_back({u, v});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cout << t << endl;

    while (t--) {
        int n = randint(1,100); // 可以调大 n 和 q 的范围以进行更强的测试
        int q = randint(1, 100); // 例如 randint(1, 100000)
        cout << n << " " << q << endl;

        const ll MAX_VAL = 1e12; // 题目要求最大值

        // 生成 a_i
        for (int i = 0; i < n; ++i) {
            cout << randint(0, 100) << (i == n - 1 ? "" : " "); // 调小一点方便观察
            // cout << randint(0, MAX_VAL) << (i == n - 1 ? "" : " ");
        }
        cout << endl;

        // 生成 b_i
        for (int i = 0; i < n; ++i) {
             cout << randint(0, 50) << (i == n - 1 ? "" : " ");
            // cout << randint(0, MAX_VAL) << (i == n - 1 ? "" : " ");
        }
        cout << endl;

        // 生成树边
        vector<pair<int, int>> edges;
        generate_tree(n, edges);
        for (const auto& edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }

        // 生成查询
        for (int i = 0; i < q; ++i) {
            int x = randint(1, n);
            ll y = randint(0, 100);
            // ll y = randint(0, MAX_VAL);
            cout << x << " " << y << endl;
        }
    }

    return 0;
}