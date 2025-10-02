#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<long long> a(n);
    for (auto &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());

    auto f = [&](long long l, long long r) -> long long {
        if (l <= r) return std::upper_bound(a.begin(), a.end(), r) - std::lower_bound(a.begin(), a.end(), l);
        else return 0;
    };  

    while (q--) {
        long long l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        std::cout << f(l1, r1) + f(l2, r2) - f(std::max(l1, l2), std::min(r1, r2)) << '\n';
    }
}