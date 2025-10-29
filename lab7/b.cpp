#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n); 
    for (int i = 0; i < n; ++i) std::cin >> a[i]; 

    int m; 
    std::cin >> m;
    std::vector<int> b(m);
    for (int j = 0; j < m; ++j) std::cin >> b[j];

    std::vector<int> c;
    c.reserve(n + m);

    int i = 0, j = 0; 
    while (i < n && j < m) {
        if (a[i] <= b[j]) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    while (i < n) c.push_back(a[i++]);
    while (j < m) c.push_back(b[j++]);

    for (size_t k = 0; k < c.size(); ++k) {
        if (k) std::cout << ' ';
        std::cout << c[k];
    }
    std::cout << '\n';
}
