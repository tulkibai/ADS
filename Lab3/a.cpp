#include <bits/stdc++.h> 

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    std::vector<int> q(t);
    int x;
    for (int i = 0; i < t; ++i) std::cin >> q[i];
    int n, m;
    std::cin >> n >> m;
    std::unordered_map<int, std::pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> x;
            p.emplace(x, std::make_pair(i, j));
        }
    }
    for (int i : q) {
        auto it = p.find(i);
        if (it == p.end()) std::cout << -1 << '\n';
        else std::cout << it->second.first << ' ' << it->second.second << '\n';
    }
}