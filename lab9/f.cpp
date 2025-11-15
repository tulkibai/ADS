#include <bits/stdc++.h>
using namespace std;

// Префикс-функция для строки s
vector<int> prefix_function(const string &s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    if (!(cin >> text >> pattern)) return 0;  

    int m = (int)pattern.size();

    // строим pattern + '#' + text
    string comb = pattern + "#" + text;
    vector<int> pi = prefix_function(comb);

    vector<int> pos;
    int n = (int)comb.size();
    for (int i = m + 1; i < n; ++i) {
        if (pi[i] == m) {
            int start = i - 2 * m;      // позиция в text (0-based)
            pos.push_back(start + 1);   // переводим в 1-based
        }
    }

    cout << pos.size() << '\n';
    for (int i = 0; i < (int)pos.size(); ++i) {
        if (i) cout << ' ';
        cout << pos[i];
    }
    cout << '\n';

    return 0;
}
