#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1, s2;
    std::stack<char> sc1, sc2;

    std::cin >> s1 >> s2;

    for (char i : s1) {
        if (!sc1.empty() && i == '#') sc1.pop();
        else sc1.push(i);
    }
    for (char i : s2) {
        if (!sc2.empty() && i == '#') sc2.pop();
        else sc2.push(i);
    }

    if (sc1 == sc2) std::cout << "Yes";
    else std::cout << "No";
}