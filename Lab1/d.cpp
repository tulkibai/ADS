#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::stack<char> s;
    char c;

    while (std::cin >> c) {
        if (!s.empty() && s.top() == c) s.pop();
        else s.push(c);        
    } 

    if (s.empty()) std::cout << "YES";
    else std::cout << "NO";
}