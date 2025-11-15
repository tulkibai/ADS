#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    queue<pair<int,int>> q;
    int mushrooms = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                q.push({i, j});          // начальные Марио
            } else if (a[i][j] == 1) {
                ++mushrooms;            // считаем грибы
            }
        }
    }

    if (mushrooms == 0) {
        cout << 0 << '\n';
        return 0;
    }

    if (q.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    int minutes = 0;
    const int dx[4] = {1, -1, 0, 0}; 
    const int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int sz = (int)q.size();
        bool changed = false;

        while (sz--) {
            auto [x, y] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (a[nx][ny] == 1) {        // есть гриб — убиваем и ставим Марио
                    a[nx][ny] = 2;
                    --mushrooms;
                    q.push({nx, ny});
                    changed = true;
                }
            }
        }

        if (changed) ++minutes;              // прошла ещё одна минута
    }

    if (mushrooms > 0) cout << -1 << '\n';
    else cout << minutes << '\n';

    return 0;
}
