#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string str;
    std::cin >> str;

    if (n == 1) {
        (str[0] == 'K') ? std::cout << "KATSURAGI" : std::cout << "SAKAYANAGI";

        return 0;
    }

    std::deque<int> k, s;
    for (int i = 0; i < n; ++i) {
        char a = str[i];

        if (a == 'K') k.push_back(i);
        else s.push_back(i);
    }

    while (!k.empty() && !s.empty()) {
        int ixk = k.front(), ixs = s.front();

        k.pop_front();
        s.pop_front();

        if (ixk < ixs) k.push_back(ixk + n);
        else s.push_back(ixs + n);
    }

    if (k.empty()) std::cout << "SAKAYANAGI";
    else std::cout << "KATSURAGI";
}