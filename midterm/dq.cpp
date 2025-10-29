template <typename T>
class DQ {
    private:
        struct Node {
            T value;
            Node *next;
            Node *prev;

            Node (const T &val, Node *nxt, Node *prv) : value (val), next (nxt), prev (prv) {}
        };

        Node *first;
        Node *last;
        size_t count;
    public:
        DQ () : first (nullptr), last (nullptr), count (0) {}

        ~DQ () {
            while (!empty()) {
                pop_back();
            }
        }

        void push_front (const T &val) {
            if (empty()) {
                Node *p = new Node (val, nullptr, nullptr);
                first = p;
                last = p;
                count++;
            }
            else {
                Node *p = new Node (val, first, nullptr);
                first->prev = p;
                first = p;
                ++count;
            }
        }

        void push_back (const T &val) {
            if (empty()) {
                Node *p = new Node (val, nullptr, nullptr);
                first = p;
                last = p;
                ++count;
            }
            else {
                Node *p = new Node (val, nullptr, last);
                last->next = p;
                last = p;
                ++count;
            }
        }

        void pop_front () {
            if (empty()) {
                cout << "Error, empty dq\n";
            }
            else {
                Node *temp = first;
                if (temp->next) {
                    temp->next->prev = nullptr;
                    first = temp->next;
                    --count;
                }
                else {
                    first = nullptr;
                    last = nullptr;
                    --count;
                }
                delete temp;
            }
        }

        void pop_back () {
            if (empty()) {
                cout << "Error, empty dq\n";
            }
            else {
                Node *temp = last;
                if (temp->prev) {
                    temp->prev->next = nullptr;
                    last = temp->prev;
                    --count;
                }
                else {
                    first = nullptr;
                    last = nullptr;
                    --count;
                }
                delete temp;
            }
        }

        T &front () {
            if (empty()) {
                cout << "Error, empty dq\n";
                static T dummy{};
                return dummy;
            }
            else {
                return first->value;
            }
        }
        
        T &back () {
            if (empty()) {
                cout << "Error, empty dq\n";
                static T dummy{};
                return dummy;
            }
            else {
                return last->value;
            }
        }

        bool empty () const {
            return first == nullptr;
        }

        size_t size () const {
            return count;
        }
};