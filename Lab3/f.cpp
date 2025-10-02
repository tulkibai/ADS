#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());

    int p;
    std::cin >> p;

    for (int i = 0; i < p; ++i) {
        int x;
        std::cin >> x;
        
        int sum = 0;
        int cnt = std::upper_bound(a.begin(), a.end(), x) - a.begin();
        for (int j = 0; j < cnt; ++j) sum += a[j];
        std::cout << cnt << ' ' << sum << '\n';
    }   
}