#include <bits/stdc++.h>


int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::string list[N];

    for (int i = 0; i < N; ++i) std::cin >> list[i];

    int c = 0, d = N;
    for (int i = K; i < d; ++i) {
        std::cout << list[i] << ' ';

        ++c;

        if (i == N - 1 && c != N) {
            i = -1;
            d = K;
        }
    }

}