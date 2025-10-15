#include <iostream> 
#include <queue>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<long long> vec(n);
    for (auto &i : vec) std::cin >> i;
    std::priority_queue<long long, std::vector<long long>> q (vec.begin(), vec.end());
    while (!q.empty()) {
        long long x, y;
        y = q.top(); q.pop();
        if (q.empty()) {
            q.push(y);
            break;
        }
        x = q.top(); q.pop();
        if (x == y) continue;
        else q.push(y - x);
    }

    if (q.empty()) std::cout << 0;
    else std::cout << q.top();
}