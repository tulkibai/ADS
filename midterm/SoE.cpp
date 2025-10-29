#include <iostream>
#include <vector>
using namespace std;

void SoE (int n, vector<bool> &res) {
    res[0] = res[1] = false;
    for (int i = 2; i * i <= n; ++i) 
        if (res[i])
            for (int j = i * i; j <= n; j += i) 
                res[j] = false;
}

int main () {
    int n;
    cin >> n;
    vector<bool> res (n + 1, true);
    SoE (n, res);
}