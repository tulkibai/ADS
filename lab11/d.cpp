#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int v) {
        return p[v] == v ? v : p[v] = find_set(p[v]);
    }
    bool unite(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) ++r[a];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    struct Edge { int u, v, w; };
    vector<Edge> edges;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({i, j, a[i][j]});
        }
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& A, const Edge& B){ return A.w < B.w; });

    DSU dsu(n);
    int used = 0;
    long long ans = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans += e.w;
            if (++used == n - 1) break;
        }
    }

    cout << ans << '\n';
    return 0;
}
