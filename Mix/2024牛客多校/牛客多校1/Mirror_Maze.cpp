#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int dx[4] = {-1 ,1, 0, 0}, dy[4] = {0, 0, -1, 1};
    // 上下左右

    int map[4][4] = {
            {1, 0, 2, 3}, // -
            {0, 1, 3, 2}, // |
            {3, 2, 1, 0}, // /
            {2, 3, 0, 1}  // \.
    };

    int n, m; cin >> n >> m;
    vector maze(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char mirror;
            cin >> mirror;
            switch (mirror) {
                case '-': maze[i][j] = 0; break;
                case '|': maze[i][j] = 1; break;
                case '/': maze[i][j] = 2; break;
                case '\\': maze[i][j] = 3; break;
            }
        }
    }


    vector step(n, vector<array<int, 4>>(m));
    vector visited(n, vector<array<bool, 4>>(m));
    vector reflected(n, vector<bool>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (visited[i][j][k]) continue;
                int x = i, y = j, d = k;
                while (!visited[x][y][d]) {
                    visited[x][y][d] = true;
                    x += dx[d];
                    y += dy[d];
                    if (!(x >= 0 && x < n && y >= 0 && y < m)) break;
                    d = map[maze[x][y]][d];
                }
                if (x == i && y == j && d == k) {
                    int cnt = 0;
                    do {
                        x += dx[d];
                        y += dy[d];
                        if (!reflected[x][y] && d != map[maze[x][y]][d]) {
                            reflected[x][y] = true;
                            cnt++;
                        }
                        d = map[maze[x][y]][d];
                    } while (!(x == i && y == j && d == k));
                    do {
                        step[x][y][d] = cnt;
                        reflected[x][y] = false;
                        x += dx[d];
                        y += dy[d];
                        d = map[maze[x][y]][d];
                    } while (!(x == i && y == j && d == k));
                } else {
                    int cnt = 0;
                    d = d ^ 1;
                    do {
                        x += dx[d];
                        y += dy[d];
                        if (!(x >= 0 && x < n && y >= 0 && y < m)) break;
                        step[x][y][d ^ 1] = cnt;
                        if (!reflected[x][y] && d != map[maze[x][y]][d]) {
                            reflected[x][y] = true;
                            cnt++;
                        }
                        d = map[maze[x][y]][d];
                    } while (true);
                    d = d ^ 1;
                    do {
                        x += dx[d];
                        y += dy[d];
                        if (!(x >= 0 && x < n && y >= 0 && y < m)) break;
                        reflected[x][y] = false;
                        d = map[maze[x][y]][d];
                        visited[x][y][d] = true;
                    } while (true);
                }
            }
        }
    }

    int q; cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v, d; string dir;
        cin >> u >> v >> dir;
        --u; --v;
        switch (dir[0]) {
            case 'a': d = 0; break;
            case 'b': d = 1; break;
            case 'l': d = 2; break;
            case 'r': d = 3; break;
        }
        cout << step[u][v][d] << '\n';
    }

    return 0;
}

