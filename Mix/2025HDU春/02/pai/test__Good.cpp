#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110, M = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const double eps = 1e-8;

int n, m, k;
char g[N][N];
int f[2][N][2][21][21][21];

int ADD(int a, int b) {
    return ((a + b) % k + k) % k;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) cin >> g[i][j];

    for (int j = 1;j <= m;j++) {
        for (int t = 0;t < 2;t++) {
            for (int a = 0;a < k;a++) {
                for (int b = 0;b < k;b++) {
                    for (int c = 0;c < k;c++) {
                        f[0][j][t][a][b][c] = 0;
                    }
                }
            }
        }
    }

    f[0][1][1][1][0][0] = 1;
    int u = 1;
    for (int i = 1;i <= n;i++, u ^= 1) {
        for (int j = 1;j <= m;j++) {
            for (int t = 0;t < 2;t++) {
                for (int a = 0;a < k;a++) {
                    for (int b = 0;b < k;b++) {
                        for (int c = 0;c < k;c++) {
                            f[u][j][t][a][b][c] = 0;
                        }
                    }
                }
            }
        }

        for (int j = 1;j <= m;j++) {
            if (g[i][j] == '+' || g[i][j] == '-') {
                int x = (g[i][j] == '+' ? 1 : 0);
                if (!(g[i - 1][j] >= '0' && g[i - 1][j] <= '9' || g[i][j - 1] >= '0' && g[i][j - 1] <= '9')) continue;
                for (int t = 0;t < 2;t++) {
                    int add = t ? 1 : -1;
                    for (int a = 0;a < k;a++) {
                        for (int b = 0;b < k;b++) {
                            for (int c = 0;c < k;c++) {
                                if (g[i][j - 1] >= '0' && g[i][j - 1] <= '9')
                                    f[u][j][x][1][0][ADD(c, add * a * b)] += f[u][j - 1][t][a][b][c],f[u][j][x][1][0][ADD(c, add * a * b)] %= mod;
                                if (g[i - 1][j] >= '0' && g[i - 1][j] <= '9')
                                    f[u][j][x][1][0][ADD(c, add * a * b)] += f[u ^ 1][j][t][a][b][c],f[u][j][x][1][0][ADD(c, add * a * b)] %= mod;
                                
                            }
                        }
                    }
                }
            }
            else if (g[i][j] == '*') {
                if (!(g[i - 1][j] >= '0' && g[i - 1][j] <= '9' || g[i][j - 1] >= '0' && g[i][j - 1] <= '9')) continue;
                for (int t = 0;t < 2;t++) {
                    int add = t ? 1 : -1;
                    for (int a = 0;a < k;a++) {
                        for (int b = 0;b < k;b++) {
                            for (int c = 0;c < k;c++) {
                                if (g[i][j - 1] >= '0' && g[i][j - 1] <= '9') {
                                    f[u][j][t][a * b % k][0][c] += f[u][j - 1][t][a][b][c];
                                    f[u][j][t][a * b % k][0][c] %= mod;
                                }
                                if (g[i - 1][j] >= '0' && g[i - 1][j] <= '9') {
                                    f[u][j][t][a * b % k][0][c] += f[u ^ 1][j][t][a][b][c];
                                    f[u][j][t][a * b % k][0][c] %= mod;
                                }
                            }
                        }
                    }
                }
            }
            else {
                int x = g[i][j] - '0';
                for (int t = 0;t < 2;t++) {
                    int add = t ? 1 : -1;
                    for (int a = 0;a < k;a++) {
                        for (int b = 0;b < k;b++) {
                            for (int c = 0;c < k;c++) {
                                f[u][j][t][a][ADD(b * 10, x)][c] += f[u][j - 1][t][a][b][c];
                                f[u][j][t][a][ADD(b * 10, x)][c] %= mod;
                                f[u][j][t][a][ADD(b * 10, x)][c] += f[u ^ 1][j][t][a][b][c];
                                f[u][j][t][a][ADD(b * 10, x)][c] %= mod;
                            }
                        }
                    }
                }
            }
        }
    }

    u ^= 1;

    ll sum = 0;
  
    for (int t = 0;t < 2;t++) {
        int add = t ? 1 : -1;
        for (int a = 0;a < k;a++) {
            for (int b = 0;b < k;b++) {
                for (int c = 0;c < k;c++) {
                    if (ADD(c, add * a * b) == 0) {
                        sum += f[u][m][t][a][b][c];
                        sum %= mod;
                    }
                }
            }
        }
    }

    cout << sum << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}