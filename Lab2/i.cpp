#include <bits/stdc++.h>

struct Node {
    std::string data;
    Node *next;
    Node *prev;

    Node(std::string _data) : data(_data), next(nullptr), prev(nullptr) {}
};

struct LinkedList {
    Node *first;
    Node *last;

    LinkedList() : first(nullptr), last(nullptr) {}

    bool empty () {
        return first == nullptr;
    }

    void push_back (std::string _data) {
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

    void add (std::string data, int pos) {
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
};

int main () { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string com;
    LinkedList *ll = new LinkedList();

    while (true) {
        std::cin >> com;
        if (com == "exit") {
            std::cout << "goodbye\n";
            break;
        }
        if (com == "add_front") {
            std::string str;
            std::cin >> str;
            ll->add(str, 0);
            std::cout << "ok\n";
        }
        if (com == "add_back") {
            std::string str;
            std::cin >> str;
            ll->push_back(str);
            std::cout << "ok\n";
        }
        if (com == "erase_front") {
            if (ll->empty()) std::cout << "error\n";
            else {
                std::cout << ll->first->data << '\n';
                ll->remove(ll->first);
            }
        }
        if (com == "erase_back") {
            if (ll->empty()) std::cout << "error\n";
            else { 
                std::cout << ll->last->data << '\n';
                ll->remove(ll->last);
            }
        }
        if (com == "front") {
            if (ll->empty()) std::cout << "error\n";
            else std::cout << ll->first->data << '\n';
        }
        if (com == "back") {
            if (ll->empty()) std::cout << "error\n";
            else std::cout << ll->last->data << '\n';
        }
        if (com == "clear") {
            ll->first = nullptr;
            ll->last = nullptr;
            std::cout << "ok\n";
        }
    }
}