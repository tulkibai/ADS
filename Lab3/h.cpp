#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<long long> a(n), p(n+1, 0);
    for (int i = 0; i < n; ++i) { std::cin >> a[i]; p[i+1] = p[i] + a[i]; }

    while (m--) {
        long long b; 
        std::cin >> b;
        int idx = lower_bound(p.begin() + 1, p.end(), b) - p.begin();
        std::cout << idx << '\n';
    }
}
