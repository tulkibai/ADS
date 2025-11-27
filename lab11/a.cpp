#include <bits/stdc++.h>
using namespace std;

struct NextDSU {
    vector<int> p;
    NextDSU(int n) : p(n + 2) { iota(p.begin(), p.end(), 0); }
    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }
    void mark(int x) { p[x] = get(x + 1); } // remove x: jump to next
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    struct Seg { int l, r; long long c; };
    vector<Seg> a(m);
    for (auto &s : a) cin >> s.l >> s.r >> s.c;

    sort(a.begin(), a.end(), [](const Seg& A, const Seg& B){ return A.c < B.c; });

    // boundaries i in [1 .. n-1]; answer = sum of minimal covering cost per boundary
    vector<long long> w(n, 0);         // 0 = unassigned (costs are >= 1)
    NextDSU jump(n);                   // jump over already assigned boundaries
    for (auto &s : a) {
        for (int i = jump.get(s.l); i < s.r; i = jump.get(i)) {
            w[i] = s.c;                // first time -> minimal cost for this boundary
            jump.mark(i);              // skip it next time
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n - 1; ++i) ans += w[i];
    cout << ans << '\n';
    return 0;
}
