#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int list[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> list[i];
    }

    int min = 100000001, ix, k;
    std::cin >> k;

    for (int i = 0; i < n; ++i) {
        int a = list[i] - k;
        a = (a < 0) ? a * -1 : a;
        if (a < min) {
            min = a;
            ix = i;
        }
    }

    std::cout << ix;
}  