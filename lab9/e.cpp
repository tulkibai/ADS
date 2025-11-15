#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        string s;
        long long k;
        cin >> s >> k;

        int n = (int)s.size();
        vector<int> pi(n, 0);

        // prefix-function for s
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j]) ++j;
            pi[i] = j;
        }

        int l = pi[n - 1];          // longest proper prefix that is also suffix
        int p = n - l;              // minimal period

        long long ans;
        if (k == 1) ans = n;
        else ans = n + (k - 1) * 1LL * p;

        cout << ans << '\n';
    }

    return 0;
}
