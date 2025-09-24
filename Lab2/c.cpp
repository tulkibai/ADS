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

    void remove (Node *p) {
        if (empty()) return;
        if (!p->next) {
            p->prev->next = p->next;
            return;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
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

    int k = 1;
    Node *p = ll->first;
    while (p) {
        if (k % 2 == 0) ll->remove(p);
        p = p->next;
        ++k;
    }

    ll->print();
}