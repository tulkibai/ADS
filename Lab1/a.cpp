#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::deque<int> deck;
        std::vector<int> res (N + 1);

        for (int i = 1; i <= N; ++i) deck.push_back(i);

        for (int step = 1; step <= N; ++step) {
            for (int i = 0; i < step; ++i) {
                int card = deck.front();
                deck.pop_front();
                deck.push_back(card);
            }

            res[deck.front()] = step;
            deck.pop_front();
        }

        for (int i = 1; i <= N; ++i) {
            std::cout << res[i];
            if (i < N) std::cout << ' ';
        }
        std::cout << '\n';
    }
}