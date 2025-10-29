template <typename T>
class Q {
    private:
        struct Node {
            T value;
            Node* next;

            Node (const T &val, Node *nxt) : value(val), next(nxt) {}
        };
        Node *first;
        size_t count;
    public: 
        Q () : head(nullptr), count(0) {}

        ~Q () {
            while (!empty()) pop();
        }

        void push (const T &val) {
            if (empty()) {
                first = new Node (val, nullptr);
                ++count;
            }
            else {
                Node *p = first;
                while (p->next) p = p->next;
                p->next = new Node (val, nullptr);
                ++count;
            }
        }

        void pop () {
            if (empty()) cout << "Error, empty queue\n";
            else {
                Node *temp = first;
                first = temp->next;
                delete temp;
                --count;
            }
        }

        T &top () {
            if (empty()) cout << "Error, empty queue\n";
            else return first->value;
        }

        bool empty () const { return first == nullptr; }

        size_t size () const { return count; }
};