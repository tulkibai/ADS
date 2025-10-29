#include <iostream>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, k;
    std::cin >> a >> k;

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> maxHeap; // минимальная куча (для топ k)
    std::priority_queue<long long> minHeap; // максимальная куча для остальных

    long long sumTopK = 0;

    for (int i = 0; i < a; ++i) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "insert") {
            long long x; std::cin >> x;

            if ((int)maxHeap.size() < k) {
                maxHeap.push(x);
                sumTopK += x;
            } else if (!maxHeap.empty() && x > maxHeap.top()) {
                long long smallestTopK = maxHeap.top();
                maxHeap.pop();
                sumTopK -= smallestTopK;

                maxHeap.push(x);
                sumTopK += x;

                minHeap.push(smallestTopK);
            } else {
                minHeap.push(x);
            }
        }
        else if (cmd == "print") {
            std::cout << sumTopK << "\n";
        }

        // Балансировка k элементов
        while ((int)maxHeap.size() > k) {
            long long val = maxHeap.top();
            maxHeap.pop();
            sumTopK -= val;
            minHeap.push(val);
        }
        while ((int)maxHeap.size() < k && !minHeap.empty()) {
            long long val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
            sumTopK += val;
        }
    }
}
