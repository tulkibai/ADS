#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::deque<int> bor(5), nur(5);
    for (int i = 0; i < 5; ++i) std::cin >> bor[i];
    for (int i = 0; i < 5; ++i) std::cin >> nur[i];

    int k = 0;
    bool b_win;
    while (k < 1000000) {
        if (bor.empty()) {
            std::cout << "Nursik " << k;
            return 0;
        }
        if (nur.empty()) {
            std::cout << "Boris " << k;
            return 0;
        }

        int b = bor.front(), n = nur.front();
        bor.pop_front(); 
        nur.pop_front();

        if (b > n) {
            if (b == 9 && n == 0) b_win = false;
            else b_win = true;
        }
        if (n > b) {
            if (n == 9 && b == 0) b_win = true;
            else b_win = false;
        }

        if (b_win) {
            bor.push_back(b);
            bor.push_back(n);
        }
        else {
            nur.push_back(b);
            nur.push_back(n);
        }

        ++k;
    }
    
    std::cout << "blin nichya";
}