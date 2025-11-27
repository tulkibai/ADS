#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
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

    int n, m;
    if (!(cin >> n >> m)) return 0;

    long long x, y;
    cin >> x >> y;

    struct Edge {
        int u, v;
        long long w;
    };
    vector<Edge> edges;
    edges.reserve(m);

    for (int i = 0; i < m; ++i) {
        string type;
        int a, b, c;
        cin >> type >> a >> b >> c;
        long long cost_per_km;
        if (type == "big")      cost_per_km = x;
        else if (type == "small") cost_per_km = y;
        else                     cost_per_km = min(x, y); // "both"
        edges.push_back({a, b, cost_per_km * c});
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& A, const Edge& B) { return A.w < B.w; });

    DSU dsu(n);
    long long ans = 0;
    int used = 0;

    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans += e.w;
            if (++used == n - 1) break;
        }
    }

    cout << ans << '\n';
    return 0;
}
