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

    string S;
    if (!getline(cin, S)) return 0;   // строка может быть пустой

    int n = (int)S.size();
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> pi = prefix_function(S);
    int period = n - pi[n - 1];      // минимальная длина исходной строки

    cout << period << '\n';
    return 0;
}
