#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, f;
    std::cin >> n >> f;

    std::vector<long long> c(n);
    long long hi = 0, lo = 1;
    for (long long &x : c) { std::cin >> x; hi = std::max(hi, x); }
    long long ans = hi;

    auto ok = [&] (long long x) -> bool {
        long long cnt = 0;
        for (long long &i : c) {
            cnt += (i + x - 1) / x;
            if (cnt > f) return false;
        } 
        return cnt <= f;
    };

    while (lo <= hi) {
        long long mid = (lo + hi) >> 1;
        if (ok(mid)) { hi = mid - 1; ans = mid; }
        else lo = mid + 1;
    }

    std::cout << ans;
} 