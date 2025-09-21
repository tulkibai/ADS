#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::stack<int> q;

    while (N--) {
        int a;
        std::cin >> a;

        while (!q.empty() && q.top() > a) q.pop();
        if (!q.empty() && q.top() <= a) {
            std::cout << q.top();
            q.push(a);
        }
        if (q.empty()) {
            std::cout << -1;
            q.push(a);
        }

        if (N >= 1) std::cout << ' ';
    }
}