#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    if (!(cin >> A >> B)) return 0;

    string cur = A;
    int cnt = 1;

    // Делаем длину cur не меньше длины B
    while (cur.size() < B.size()) {
        cur += A;
        ++cnt;
    }

    // Проверяем при cnt и при cnt + 1 повторениях
    if (cur.find(B) != string::npos) {
        cout << cnt << '\n';
        return 0;
    }

    cur += A;
    ++cnt;
    if (cur.find(B) != string::npos) {
        cout << cnt << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
