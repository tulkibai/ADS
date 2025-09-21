#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);   
    std::cin.tie(nullptr);

    int a;
    std::cin >> a;

    if (a == 2 || a == 3 || a == 5) {
        std::cout << "YES";
        return 0;
    }
    if (a == 1 || a % 2 == 0 || a % 3 == 0 || a % 5 == 0) {
        std::cout << "NO";
        return 0;
    }

    for (int i = 7; i * i <= a; i += 2) {
        if (a % i == 0) {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";
}