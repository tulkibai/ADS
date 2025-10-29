#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

void sieve (vector<bool> &res) {
    int n = res.size();
    res[0] = res[1] = false;
    for (int i = 2; i * i <= n; ++i) 
        if (res[i])
            for (int j = i * i; j <= n; ++j)
                res[j] = false;
}

int main () {
    int n;
    cin >> n;

    int limit = sqrt(n) + 1;
    vector<bool> res(limit + 1, true);

    sieve(res);
}