#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];

    int s, t;
    cin >> s >> t;
    --s;  // переводим к 0-индексации
    --t;

    vector<int> dist(n, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 0; u < n; ++u) {
            if (g[v][u] == 1 && dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    cout << dist[t] << '\n';  // если пути нет, здесь будет -1
    return 0;
}
