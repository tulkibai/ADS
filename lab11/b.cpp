#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> d(n);
    long long sum = 0, minVal = LLONG_MAX;
    
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
        minVal = min(minVal, d[i]);
    }
    
    long long ans = (n - 2) * minVal + sum;
    cout << ans << '\n';
    
    return 0;
}
