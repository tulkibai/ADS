#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    if (N == 1) {
        std::cout << 2;
        return 0;
    }

    std::vector<int> list(7920, 0);

    int k = 1;
    for (int i = 3; i <= 7920; i += 2) {
        if (list[i] == 0) {
            ++k;
            if (k == N) {
                std::cout << i;
                return 0;
            }
            for (int j = i * i; j <= 7920; j += i) ++list[j];
        }
    }
}