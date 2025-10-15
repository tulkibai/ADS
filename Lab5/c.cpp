#include <iostream>
#include <queue>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;

    std::vector<long long> vec(n);
    for (auto &i : vec) std::cin >> i;
    std::priority_queue<long long, std::vector<long long>> q (vec.begin(), vec.end());

    long long res = 0;
    for (int i = 0; i < x; ++i) {
        long long t = q.top();
        q.pop();
        res += t;
        q.push(t - 1);
    }

    std::cout << res;
}