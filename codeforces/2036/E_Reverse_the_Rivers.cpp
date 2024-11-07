#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> g(n + 1, vector<int>(k + 1));
    rep(i, 1, n) rep(j, 1, k) cin >> g[i][j];
    rep(i, 1, n) rep(j, 1, k) g[i][j] |= g[i - 1][j];
    // rep(i, 1, n) {
    //     rep(j, 1, k) cout << g[i][j] << ' ';
    //     cout << '\n';
    // }

    while (q--) {
        int m;
        cin >> m;
        int ansl = -0x3f3f3f3f, ansr = 0x3f3f3f3f;
        rep(times, 1, m) {
            int x, c;
            char o;
            cin >> x >> o >> c;
            if (o == '>') {
                int l = 1, r = n + 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (g[mid][x] > c)
                        r = mid;
                    else
                        l = mid + 1;
                }
                // cout << l << '\n';
                // lp[x] = l;
                ansl = max(ansl, l);
            } else {
                int l = 0, r = n;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (g[mid][x] < c)
                        l = mid;
                    else
                        r = mid - 1;
                }
                // cout << l << '\n';
                // rp[x] = l;
                ansr = min(ansr, l);
            }
        }
        
        // cout << ansl << ' ' << ansr;
        // cout << '\n';
        if(ansr == 0x3f3f3f3f) ansr = n;
        if(ansl == -0x3f3f3f3f) ansl = 1;
        if(ansl > ansr) cout << -1 << '\n';
        else cout << ansl << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
}