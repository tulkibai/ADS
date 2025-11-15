#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, T;
    int K;
    if (!(cin >> s >> K)) return 0;
    if (!(cin >> T)) return 0;

    string concat = s + '#' + T;
    int n = concat.size();
    vector<int> pi(n, 0);

    // Строим префикс-функцию (КМП)
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && concat[i] != concat[j])
            j = pi[j - 1];
        if (concat[i] == concat[j]) ++j;
        pi[i] = j;
    }

    int m = s.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        // Вхождения считаем только в части T (после s + '#')
        if (pi[i] == m) {
            ++count;
            if (count >= K) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}
