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
            std::cout << p->data << ' ';
            p = p->next;
        }
        std::cout << '\n';
    }

    void add (int data, int pos) {
        if (empty()) {
            push_back(data);
            return;
        }
        int k = 0;
        Node *p = first, *a = new Node(data);
        while (p) {
            if (k == pos) break;
            ++k;
            p = p->next;
        }
        if (!p) {
            push_back(data);
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

    void remove (Node *p) {
        if (empty()) return;
        if (p->next) p->next->prev = p->prev;
        else last = p->prev;
        if (p->prev) p->prev->next = p->next;
        else first = p->next;
    }

    void reverse () {
        Node *i1, *i2;
        first = last;
        Node *p = first;
        while (p) {
            i1 = p->next;
            i2 = p->prev;
            p->next = p->prev;
            p->prev = i1;
            if (i2 == nullptr) last = p;
            p = i2;
        }
    }

    void left_shift (int x) {
        if (x == 0) return;
        Node *p = first;
        Node *i = first;
        int n = -1;
        int k = 0;
        //0 1 2 3 4 5
        // L5 5 0 1 2 3 4
        //Node 5 (-, 0) k = 5, 0 (-, 1) 6, 1 (0, 2) 7, 3 (2, 4) 8, 4 (3, -) 9
        // 0 1 2 3 4 5
        // L5 5 0 1 2 3 4
        // Node 5 (-, 0), 0 (5, 1), 1 (0, 2), 2 (1, 3), 3 (2, 4), 4 (3, -)
        while (p) {
            if (k >= x) {
                if (k == x) {
                    p->prev = nullptr;
                    first = p;
                    if (p->next) first->next = p->next;
                }
                if (!p->next) {
                    if (k == x) first->next = i;
                    p->next = i;
                    n = k;
                }
                // 0 1 | 2 3 4 5
                // L2 2 3 4 5 | 0 1
                if (n != -1 && k - n == 1) { //cycle
                    p->prev = last;
                }
                if (n != -1 && (n + x) == k) {
                    p->next = nullptr;
                    last = p;
                    break;
                }
            }
            p = p->next;
            ++k;
        }
    }

    void right_shift (int x) {
        if (x == 0) return;
        Node *p = last;
        Node *i = last;
        int k = 0, n = -1;
        while (p) {
            if (k >= x) {
                if (k == x) {
                    p->next = nullptr;
                    last = p;
                    if (p->prev) last->prev = p->prev;
                }
                if (!p->prev) {
                    if (k == x) last->prev = i;
                    p->prev = i;
                    n = k;
                }
                if (n != -1 && k - n == 1) { //cycle
                    p->next = first;
                }
                if (n != -1 && (n + x) == k) {
                    p->prev = nullptr;
                    first = p;
                    break;
                }
            }   
            p = p->prev;
            ++k;
        }
    }
};

int main () { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int com;
    LinkedList *ll = new LinkedList();

    while (true) {
        std::cin >> com;
        if (com == 0) break;
        if (com == 1) {
            int x, p;
            std::cin >> x >> p;
            ll->add(x, p);
        }
        if (com == 2) {
            int pos;
            std::cin >> pos;

            int k = 0;
            Node *p = ll->first;
            while (p) {
                if (pos == k) break;
                p = p->next;
                ++k;
            }
            ll->remove(p);
        }
        if (com == 3) {
            if (ll->empty()) std::cout << -1 << '\n';
            else ll->print();
        }
        if (com == 4) {
            int p1, p2;
            std::cin >> p1 >> p2;

            Node *p = ll->first;
            int k = 0;
            while (p) {
                if (k == p1) break;
                p = p->next;
                ++k;
            }

            ll->remove(p);
            ll->add(p->data, p2);
        }
        if (com == 5) {
            ll->reverse();
        }
        if (com == 6) {
            int x;
            std::cin >> x;
            ll->left_shift(x);
        }
        if (com == 7) {
            int x;
            std::cin >> x;
            ll->right_shift(x);
        }
    }
}