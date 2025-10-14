#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<long long> v(n);
    for (auto &i : v) std::cin >> i;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q (v.begin(), v.end());

    long long res = 0;
    while (q.size() > 1) {
        long long a = q.top(); q.pop();
        long long b = q.top(); q.pop();
        res += a + b;
        q.push(a + b);
    }

    std::cout << res;
}