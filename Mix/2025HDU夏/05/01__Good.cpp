#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

using ll = long long;

struct Enemy {
    int id;
    ll required_level;

    // 自定义比较，用于小顶堆
    bool operator>(const Enemy& other) const {
        return required_level > other.required_level;
    }
};

void solve() {
    int n;
    int q;
    cin >> n >> q;

    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < q; ++i) {
        int start_node;
        ll initial_level;
        cin >> start_node >> initial_level;

        ll current_level = initial_level;
        
        priority_queue<Enemy, vector<Enemy>, greater<Enemy>> pq;
        vector<bool> visited(n + 1, false);

        // 初始战斗在出生点
        pq.push({start_node, a[start_node]});

        while (!pq.empty()) {
            Enemy current_enemy = pq.top();
            
            // 如果当前等级不足以击败最弱的敌人，则结束
            if (current_level < current_enemy.required_level) {
                break;
            }
            
            // pop出可以击败的敌人
            pq.pop();
            int u = current_enemy.id;

            // 可能因为从不同路径到达而重复入队
            if (visited[u]) {
                continue;
            }

            // 胜利
            visited[u] = true;
            current_level += b[u];

            // 将新的可达敌人加入队列
            for (int neighbor : adj[u]) {
                if (!visited[neighbor]) {
                    pq.push({neighbor, a[neighbor]});
                }
            }
        }
        cout << current_level << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}