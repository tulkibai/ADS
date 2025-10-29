#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    struct Row {
        long long sum;
        vector<long long> a;
    };
    vector<Row> rows;
    rows.reserve(n);

    for (int i = 0; i < n; ++i) {
        Row r; r.sum = 0; r.a.resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> r.a[j];
            r.sum += r.a[j];
        }
        rows.push_back(move(r)); // перенос а не копирование  
    }

    stable_sort(rows.begin(), rows.end(), [&](const Row& x, const Row& y) {
        if (x.sum != y.sum) return x.sum > y.sum; // по убыванию суммы
        // лексикографически по возрастанию
        for (int j = 0; j < m; ++j) {
            if (x.a[j] != y.a[j]) return x.a[j] < y.a[j];
        }
        return false; // полностью равные: сохранить исходный порядок (стабильность)
    });

    for (const auto& r : rows) {
        for (int j = 0; j < m; ++j) {
            if (j) cout << ' ';
            cout << r.a[j];
        }
        cout << " \n";
    }
    return 0;
}
