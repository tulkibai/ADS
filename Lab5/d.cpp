#include <iostream>
#include <queue>
int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long m;
    std::cin >> m;

    std::vector<long long> v(n);
    for (auto &i : v) std::cin >> i;   
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q (v.begin(), v.end());

    int k = 0;
    while (!q.empty()) {
        if (q.top() >= m) break;

        long long dln, dl1, dl2;
        dl1 = q.top(); q.pop();
        if (q.empty()) {
            q.push(dl1);
            break;
        }
        dl2 = q.top(); q.pop();

        dln = dl1 + (2 * dl2);
        q.push(dln);

        ++k;
    }

    if (q.top() >= m) std::cout << k;
    else std::cout << -1;
}   