#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    std::string line;
    std::getline(std::cin, line); // захват оставшегося перевода строки

    for (int tc = 0; tc < T; ++tc) {
        std::getline(std::cin, line);
        std::istringstream iss(line); // работа с строкой как с потоком ввода, по типу cin

        std::vector<std::string> words;
        std::string w;
        while (iss >> w) words.push_back(w);

        std::stable_sort(words.begin(), words.end(),
                         [](const std::string& a, const std::string& b) {
                             return a.size() < b.size();
                         });

        for (size_t i = 0; i < words.size(); ++i) {
            if (i) std::cout << ' ';
            std::cout << words[i];
        }
        std::cout << '\n';
    }
    return 0;
}
