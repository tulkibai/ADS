#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &i : a) std::cin >> i;

    int x;
    std::cin >> x;

    int lo = a[0], hi = a[n - 1];
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (x < mid) hi = mid - 1;
        if (x > mid) lo = mid + 1;
        if (x == mid) { std::cout << "Yes"; return 0; }
    }
    std::cout << "No";
}