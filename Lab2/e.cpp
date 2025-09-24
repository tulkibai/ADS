#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::string str, prev = "";

    std::stack<std::string> q;

    int g = n;
    for (int i = 0; i < g; ++i) {
        std::cin >> str;
        if (str != prev) q.push(str);
        else --n;
        prev = str;
    }

    std::cout << "All in all: " << n << '\n';
    std::cout << "Students: \n";
    while (!q.empty()) {
        std::string s = q.top();
        q.pop();
        std::cout << s << '\n';
    }
}