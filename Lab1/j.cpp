#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    char a;
    std::deque<int> list;

    while (std::cin >> a) {
        if (a == '!') break;

        if (a == '*') {
            if (!list.empty()) {
                std::cout << list.front() + list.back() << '\n';

                list.pop_front();
                if (!list.empty()) list.pop_back();
            }

            else std::cout << "error\n";
        }

        else {
            std::cin >> x;

            if (a == '+') list.push_front(x);
            else list.push_back(x);
        }
    }
}