#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using ll = long long;
using namespace std;
const ll MOD = 1e9 + 7;

ll qPow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % MOD;
        n >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int main() {
    ll n, k; cin >> n >> k;
    priority_queue<ll, vector<ll>, greater<>> q;
    ll max_a = 0;
    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;
        q.push(a);
        max_a = max(max_a, a);
    }
    for (; k > 0 && q.top() * 2 < max_a; --k) {
        q.push(q.top() * 2);
        q.pop();
    }
    ll sum = 0;
    vector<ll> a; a.reserve(n);
    for (int i = 0; i < n; ++i) {
        a.push_back(q.top());
        sum += a[i];
        q.pop();
    }
    sum %= MOD;
    ll mul = qPow(2, k / n);
    sum = sum * mul % MOD;
    for (int i = 0; i < k % n; ++i)
        sum = (sum + a[i] * mul % MOD) % MOD;
    cout << sum;
    return 0;
}