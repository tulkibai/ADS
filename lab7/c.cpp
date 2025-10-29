#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::unordered_map<long long, int> cnt;
    for (int i = 0; i < n; ++i) {
        long long x; std::cin >> x;
        ++cnt[x];
    }

    std::vector<long long> out;
    out.reserve(std::max(n, m));
    for (int j = 0; j < m; ++j) {
        long long y; std::cin >> y;
        auto it = cnt.find(y);
        if (it != cnt.end() && it->second > 0) {
            out.push_back(y);
            --(it->second);
        }
    }

    std::sort(out.begin(), out.end());

    for (size_t i = 0; i < out.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << out[i];
    }
    std::cout << '\n';
}
