#include <bits/stdc++.h>

int main () { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    long long lo = 0, hi = 0;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        lo = std::max(lo, a[i]);
        hi += a[i];
    }

    if (n == k) {
        std::cout << lo;
        return 0;
    }
    if (k == 1) {
        std::cout << hi;
        return 0;
    }

    auto ok = [&](long long x) {
        int cnt = 1;
        long long s = 0;
        for (long long i : a) {
            if (s + i > x) {++cnt; s = i;}
            else s += i;
        }
        return cnt <= k;
    };

    while (lo < hi) {
        long long mid = (lo + hi) >> 1;
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }

    std::cout << lo;
}