#include <bits/stdc++.h>
using namespace std;

string to_lower(const string &s) {
    string t = s;
    for (char &c : t)
        c = (char)tolower((unsigned char)c);
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string P;
    if (!(cin >> P)) return 0;
    int N;
    cin >> N;

    vector<string> cities(N);
    for (int i = 0; i < N; ++i)
        cin >> cities[i];

    string P_low = to_lower(P);                     // работаем в нижнем регистре [file:36]

    int best = 0;
    vector<int> val(N);

    for (int i = 0; i < N; ++i) {
        string city_low = to_lower(cities[i]);      // префикс города в нижнем регистре [file:36]
        string s = city_low + "#" + P_low;          // pattern + '#' + text [file:36]

        int len = (int)s.size();
        vector<int> pi(len);
        for (int j = 1; j < len; ++j) {             // стандартная префикс‑функция [file:36]
            int k = pi[j - 1];
            while (k > 0 && s[j] != s[k])
                k = pi[k - 1];
            if (s[j] == s[k]) ++k;
            pi[j] = k;
        }

        val[i] = pi[len - 1];                       // длина наибольшего префикса города,
                                                    // являющегося суффиксом P [file:36]
        best = max(best, val[i]);
    }

    // Важно: пустой суффикс (длина 0) не считается, поэтому, если best == 0,
    // ходов нет вовсе. [file:36]
    if (best == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i)
        if (val[i] == best) ++cnt;

    cout << cnt << '\n';
    for (int i = 0; i < N; ++i)
        if (val[i] == best)
            cout << cities[i] << '\n';

    return 0;
}
