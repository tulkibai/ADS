#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; long long k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (auto &x : a) std::cin >> x;
    
    long long s = 0;
    int ans = n + 1, l = 0;
    for (int r = 0; r < n; ++r) {
        s += a[r];
        while (s >= k) {
            ans = std::min(ans, r - l + 1);
            s -= a[l++];
        }
    }
    std::cout << ans;
}