#include <bits/stdc++.h>

using i64 = long long;

int power(int a, int b, int p) {
    int res = 1 % p;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, seed, vmax;
    std::cin >> n >> m >> seed >> vmax;
    
    auto rnd = [&]() {
        int ret = seed;
        seed = (seed * 7LL + 13) % 1000000007;
        return ret;
    };
    
    std::vector<int> a(n);
    
    std::map<int, i64> f;
    for (int i = 0; i < n; i++) {
        a[i] = rnd() % vmax + 1;
        f[i] = a[i];
    }
    f[n] = -1;
    
    auto split = [&](int i) {
        auto it = std::prev(f.upper_bound(i));
        if (it->first != i) {
            f[i] = it->second;
        }
    };
    
    for (int i = 0; i < m; i++) {
        int op = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1;
        if (l > r) {
            std::swap(l, r);
        }
        l--;
        
        int x;
        if (op == 3) {
            x = rnd() % (r - l);
        } else {
            x = rnd() % vmax + 1;
        }
        
        split(l);
        split(r);
        if (op == 1) {
            for (auto it = f.find(l); it->first != r; it++) {
                it->second += x;
            }
        } else if (op == 2) {
            for (auto it = f.find(l); it->first != r; it = f.erase(it))
                ;
            f[l] = x;
        } else if (op == 3) {
            std::vector<std::array<i64, 2>> v;
            for (auto it = f.find(l); it->first != r; it++) {
                v.push_back({it->second, std::next(it)->first - it->first});
            }
            std::sort(v.begin(), v.end());
            for (auto [a, b] : v) {
                if (x < b) {
                    std::cout << a << "\n";
                    break;
                }
                x -= b;
            }
        } else {
            int y = rnd() % vmax + 1;
            int ans = 0;
            for (auto it = f.find(l); it->first != r; it++) {
                ans = (ans + 1LL * (std::next(it)->first - it->first) * power(it->second % y, x, y)) % y;
            }
            std::cout << ans << "\n";
        }
    }
    
    return 0;
}