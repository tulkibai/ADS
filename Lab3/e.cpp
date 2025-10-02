#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (auto &x : a) {
        long long x1, x2, x3, x4;
        std::cin >> x1 >> x2 >> x3 >> x4;
        x = std::max(x3, x4);
    }

    std::sort(a.begin(), a.end());
    std::cout << a[k - 1];
}