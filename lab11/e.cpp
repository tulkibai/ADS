#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int v) {
        return (p[v] == v) ? v : (p[v] = find_set(p[v]));
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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DSU dsu(n);
    vector<int> res(n + 2, 0);
    vector<char> active(n + 1, 0);
    int comp = 0;

    for (int k = n; k >= 1; --k) {
        active[k] = 1;
        ++comp;
        for (int to : adj[k]) {
            if (active[to] && dsu.unite(k, to)) {
                --comp;
            }
        }
        res[k] = comp;
    }

    for (int i = 1; i <= n - 1; ++i)
        cout << res[i + 1] << '\n';
    cout << 0 << '\n';

    return 0;
}
