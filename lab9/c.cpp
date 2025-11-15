#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    if (!(cin >> s >> t)) return 0;

    if (s.size() != t.size()) {
        cout << -1 << '\n';
        return 0;
    }

    int n = (int)s.size();
    string d = s + s;              // все циклические сдвиги s как подстроки d

    size_t pos = d.find(t);
    if (pos == string::npos || pos >= (size_t)n) {
        cout << -1 << '\n';
    } else {
        int shiftRight = (n - (int)pos) % n;  // минимальный сдвиг вправо
        cout << shiftRight << '\n';
    }

    return 0;
}
