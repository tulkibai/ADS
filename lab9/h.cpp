#include <bits/stdc++.h>
using namespace std;

// Z-функция: z[i] — длина наибольшего префикса,
// совпадающего с подстрокой, начинающейся в i
vector<int> z_function(const string &s) {
    int n = (int)s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    int n = (int)s.size();
    vector<int> z = z_function(s);

    long long ans = 0;
    int limit = (n - 1) / 2;   // максимум для |a| = |b|
    for (int i = 1; i <= limit; ++i) {
        if (z[i] >= i)         // префикс длины i совпадает с подстрокой s[i..2i-1]
            ++ans;
    }

    cout << ans << '\n';
    return 0;
}
