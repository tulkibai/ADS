#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::deque<char> q;
        int l[26] = {0};
        for (int i = 0; i < n; ++i) {
            char x;
            std::cin >> x;
            ++l[x - 'a'];
            q.push_back(x);
            while (!q.empty() && l[q.front() - 'a'] > 1) q.pop_front();
            if (i) std::cout << ' ';
            if (q.empty()) std::cout << -1;
            else std::cout << q.front();
        }
        if (t) std::cout << '\n';
    }
}