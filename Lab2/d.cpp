#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        ++mp[a];
    }

    std::set<std::pair<int, int>, std::greater<std::pair<int, int>>> st;
    for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) st.emplace(it->second, it->first); 

    for (std::set<std::pair<int, int>, std::greater<std::pair<int, int>>>::iterator it = st.begin(); it != st.end(); it++) {
        std::cout << it->second << " ";
        if (it->first != (std::next(it)->first)) break;
    }
}