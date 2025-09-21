#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;  

    std::vector<bool> list(3912, true);
    int k1 = 1, k2 = 0;

    for (int i = 3; i <= 3911; i += 2) {
        if (list[i]) {
            ++k1;
            if (k1 % 2 != 0 || k1 == 2) {
                if (list[k1]) {
                    ++k2;
                    if (k2 == n) {
                        std::cout << i;
                        return 0;
                    }
                }
            }

            for (int j = i * i; j <= 3911; j += i) list[j] = false;
        }
    }
}