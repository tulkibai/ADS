#include <bits/stdc++.h>

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int _data) : data(_data), next(nullptr), prev(nullptr) {}
};

struct LinkedList {
    Node *first;
    Node *last;

    LinkedList() : first(nullptr), last(nullptr) {}

    bool empty () {
        return first == nullptr;
    }

    void push_back (int _data) {
        Node* p = new Node(_data);

        if (empty()) {
            first = p;
            last = p;
            return;
        }

        Node* prev_it = last;
        last->next = p;
        last = p;
        last->prev = prev_it;
    }

    void print () {
        if (empty()) return;
        Node* p = first;
        while (p) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << '\n';
    }

    void add (int data, int pos) {
        int k = 0;
        Node *p = first;
        Node *a = new Node(data);

        while (p) {
            if (k == pos) break;
            ++k;
            p = p->next;
        }
        
        if (k != pos) {
            Node* prev_it = last;
            last->next = a;
            a->prev = prev_it;
            last = a;
            return;
        }

        if (k != 0) {
            a->prev = p->prev;
            p->prev->next = a;
        }
        if (k == 0) first = a;
        a->next = p;
        p->prev = a;
    }
};

int main () { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    LinkedList *ll = new LinkedList();

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        ll->push_back(a);
    }

    int a, b;
    std::cin >> a >> b;

    ll->add(a, b);

    ll->print();
}