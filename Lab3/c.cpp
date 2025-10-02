#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<long long> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];

    while (q--) {
        long long l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        int cnt = 0;
        for (auto a : v) if ((a >= l1 && a <= r1) || (a >= l2 && a <= r2)) ++cnt;
        std::cout << cnt << '\n';
    }
}