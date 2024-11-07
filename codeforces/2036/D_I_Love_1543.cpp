#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
    int rs = 0;
    rep(times, 1, min(n, m) / 2) {
        vector<char> a;
        int c1 = times, c2 = m - times + 1;
        int r1 = times, r2 = n - times + 1;
        rep(i, c1, c2) a.emplace_back(g[r1][i]);
        rep(i, r1 + 1, r2 - 1) a.emplace_back(g[i][c2]);
        per(i, c2, c1) a.emplace_back(g[r2][i]);
        per(i, r2 - 1, r1 + 1) a.emplace_back(g[i][c1]);
        int len = a.size();
        // for (auto x : a) cout << x << ' ';
        // cout << '\n';
        rep(i, 0, len - 1) {
            if (a[i] == '1' && a[(i + 1) % len] == '5' &&
                a[(i + 2) % len] == '4' && a[(i + 3) % len] == '3') {
                rs++;
            }
        }
    }
    cout << rs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}