#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val, Node* nxt) : value(val), next(nxt) {}
    };

    Node* head;  // вершина стека
    size_t count; // количество элементов

public:
    Stack() : head(nullptr), count(0) {}

    ~Stack() {
        while (!empty()) pop();
    }

    // Добавить элемент в стек
    void push(const T& value) {
        head = new Node(value, head);
        count++;
    }

    // Удалить элемент с вершины стека
    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    // Получить элемент на вершине
    T& top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return head->value;
    }

    // Проверка на пустоту
    bool empty() const {
        return head == nullptr;
    }

    // Размер стека
    size_t size() const {
        return count;
    }
};

int main() {
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    std::cout << "Top element: " << st.top() << std::endl; // 30
    st.pop();
    std::cout << "Top after pop: " << st.top() << std::endl; // 20

    std::cout << "Stack size: " << st.size() << std::endl; // 2
    std::cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << std::endl; // No

    st.pop();
    st.pop();

    std::cout << "Is stack empty now? " << (st.empty() ? "Yes" : "No") << std::endl; // Yes

    return 0;
}
