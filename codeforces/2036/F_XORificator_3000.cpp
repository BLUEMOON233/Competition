#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

LL f(LL x) {
    if (x % 4 == 0)
        return x;
    else if (x % 4 == 1)
        return 1;
    else if (x % 4 == 2)
        return x + 1;
    else if (x % 4 == 3)
        return 0;
}

LL g(LL x, LL i, LL k) {
    if(x < k) return 0;
    LL t = (x - k) >> i;
    LL ret = f(t) << i;
    if(t % 2 == 0) ret ^= k;
    return ret;
}

void solve() {
    LL l, r, i, k;
    cin >> l >> r >> i >> k;
    cout << (f(r) ^ f(l - 1) ^ g(r, i, k) ^ g(l - 1, i, k)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}