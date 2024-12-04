#include <bits/stdc++.h>

using namespace std;
int dic[256];

void solve(){
    int n; cin >> n;
    char d1; int num;
    cin >> d1 >> num;
    cout << n * 2 - 1 << ' ' << d1 << '\n';
    cout << 'Z' << ' ' << num << '\n';
    for (int i = 1; i < n; ++i) {
        char d2;
        cin >> d2 >> num;
        if (dic[d2] == (dic[d1] + 1) % 4)
            cout << 'R' << '\n';
        else
            cout << 'L' << '\n';
        cout << 'Z' << ' ' << num << '\n';
        d1 = d2;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    dic['N'] = 0;
    dic['E'] = 1;
    dic['S'] = 2;
    dic['W'] = 3;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}