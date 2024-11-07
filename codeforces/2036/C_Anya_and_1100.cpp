#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    int len = s.length();
    s = '@' + s;

    int cnt = 0;
    vector<bool> flag(len + 1, false);
    rep(i, 1, len) {
        if (s.substr(i, 4) == "1100") {
            cnt++;
            flag[i] = true;
        }
    }
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        if (s[u] != '0' + v) {
            s[u] = '0' + v;
            // cout << s << '\n';
            rep(j, max(u - 3, 1), u) {
                // cout << s.substr(j, 4) << '\n';
                if (s.substr(j, 4) == "1100")
                    cnt++, flag[j] = true;
                else if (flag[j])
                    cnt--, flag[j] = false;
            }
        }
        // cout << cnt << '\n';
        if (cnt)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}