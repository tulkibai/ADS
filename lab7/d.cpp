#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, double> val{
        {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},
        {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00},
        {"F", 0.00}
    };

    struct S { string last, first; double gpa; };
    vector<S> v;
    v.reserve(n);

    for (int i = 0; i < n; ++i) {
        string last, first; int m;
        cin >> last >> first >> m;
        double num = 0.0;
        long long den = 0;
        for (int j = 0; j < m; ++j) {
            string grade; long long c; 
            cin >> grade >> c;
            num += val[grade] * c;
            den += c;
        }
        v.push_back({last, first, den ? num / den : 0.0});
    }

    stable_sort(v.begin(), v.end(), [](const S& a, const S& b){
        if (fabs(a.gpa - b.gpa) > 1e-12) return a.gpa < b.gpa; // по возрастанию GPA
        if (a.last != b.last) return a.last < b.last;          // затем по фамилии
        return a.first < b.first;                               // затем по имени
    });

    cout.setf(ios::fixed);
    cout << setprecision(3);
    for (const auto& s : v) cout << s.last << ' ' << s.first << ' ' << s.gpa << '\n';
}
