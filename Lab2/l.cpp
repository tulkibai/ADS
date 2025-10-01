#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int x;
    std::cin >> x;
    int s = x;
    int ans = s;
    for (int i = 1; i < n; ++i) {
        std::cin >> x;
        s = std::max(x, s + x);
        ans = std::max(s, ans);
    }
    std::cout << ans;
}