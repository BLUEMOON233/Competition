#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, LL> mp;
    rep(i, 1, k) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    vector<LL> rs;
    for (auto [u, v] : mp) rs.emplace_back(v);
    LL ans = 0;
    sort(rs.begin(), rs.end(), [&](LL a, LL b) { return a > b; });
    rep(i, 1, min(n, (int)rs.size())) ans += rs[i - 1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}